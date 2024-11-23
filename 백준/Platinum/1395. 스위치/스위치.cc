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
    const int n;
    T *tree, *lazy, *len;

    void init(vector<T> &a){
      for(int i = 0; i < n; i++){
        len[i + n] = 1;
        tree[i + n] = a[i];
      }
      for(int i = n - 1; i > 0; i--){
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
        len[i] = len[i << 1] << 1;
      }
    }

    void apply(int p){
      tree[p] = abs(tree[p] - len[p]);
      if(p < n) lazy[p]++;      
    }

    void build(int p){
      for(p >>= 1; p > 0; p >>= 1){
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
        if(~lazy[p] & 1) continue;
        tree[p] = abs(tree[p] - len[p]);
      }
    }

    void push(int p){
      for(int h = __lg(p); h > 0; h--){
        int cur = p >> h;
        if(lazy[cur] & 1){
          apply(cur << 1);
          apply(cur << 1 | 1);
          lazy[cur] = 0;
        }
      }
    }

  public:
    LazySegmentTree(vector<T> &a): n(a.size()) {
      tree = new T[n << 1]();
      lazy = new T[n << 1]();
      len = new T[n << 1]();
      init(a);
    }

    void update_range(int l, int r){
      for(int L = l + n, R = r + n; L < R; L >>= 1, R >>= 1){
        if(L & 1) apply(L++);
        if(R & 1) apply(--R);
      }
      build(l + n);
      build(r + n - 1);
    }

    T query(int l, int r){
      T ret{};
      push(l += n); push((r += n) - 1);
      for(; l < r; l >>= 1, r >>= 1){
        if(l & 1) ret += tree[l++];
        if(r & 1) ret += tree[--r];
      }
      return ret;
    }
};

int n, m;

int main() {
  fastio(nullptr, false);

  cin >> n >> m;

  vi a(n);
  LazySegmentTree<int> lazySeg(a);

  while(m--){
    int o, s, t;
    cin >> o >> s >> t;

    if(!o){
      lazySeg.update_range(s-1, t);
      continue;
    }

    cout << lazySeg.query(s-1, t) << nl;
  }
}