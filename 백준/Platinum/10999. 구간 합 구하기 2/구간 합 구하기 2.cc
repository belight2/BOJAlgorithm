#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

template<typename T>
class LazySegmentTree{
  private:
    int n;
    vector<T> tree, lazy;

    void build(vector<T> &a, int p, int l, int r){
      if(l == r){
        tree[p] = a[l];
        return;
      }
      int m = (l + r) >> 1;
      build(a, p << 1, l, m);
      build(a, p << 1 | 1, m+1, r);
      tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    void propagate(int p, int l, int r){
      if(lazy[p] == 0) return;
      tree[p] += (r - l + 1) * lazy[p];
      if(l != r){
        lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
      }
      lazy[p] = 0;
    }

    void update(int p, int l, int r, int st, int en, T val){
      propagate(p, l, r);
      
      if(r < st || en < l) return;
      if(st <= l && r <= en){
        lazy[p] = val;
        propagate(p, l, r);
        return;
      }

      int m = (l + r) >> 1;
      update(p << 1, l, m, st, en, val);
      update(p << 1 | 1, m+1, r, st, en, val);
      tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    T sum_query(int p, int l, int r, int st, int en){
      propagate(p, l, r);
      if(r < st || en < l) return 0;
      if(st <= l && r <= en) return tree[p];
      int m = (l + r) >> 1;
      return sum_query(p << 1, l, m, st, en) + sum_query(p << 1 | 1, m + 1, r, st, en);
    }
  
  public:
    LazySegmentTree(int n): n(n), tree(4 * n), lazy(4 * n) {}
    LazySegmentTree(vector<T> &a) : LazySegmentTree(a.size()){
      build(a, 1, 0, n - 1);
    }

    void update(int st, int en, T val){
      update(1, 0, n - 1, st, en, val);
    }

    T sum_query(int st, int en){
      return sum_query(1, 0, n - 1, st, en);
    }
};

int n, m, k;

int main() {
  fastio(nullptr, false);

  cin >> n >> m >> k;
  vl a(n);
  for(auto &x : a) cin >> x;

  LazySegmentTree<ll> LST(a);
  
  m += k;
  while(m--){
    ll a, b, c, d;
    cin >> a >> b >> c;
    if(a&1){
      cin >> d;
      LST.update(b-1, c-1, d);
    }
    else{
      cout << LST.sum_query(b-1, c-1) << nl;
    }
  }
}