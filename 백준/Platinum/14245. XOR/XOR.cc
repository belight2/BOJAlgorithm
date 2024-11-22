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
    T *tree, *lazy;

    void init(vector<T> &a){
      for(int i = 0; i < n; i++) tree[i + n] = a[i];
      for(int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
    }
    
    void apply(int p, T val){
      if(p >= n) tree[p] ^= val;
      if(p < n) lazy[p] ^= val;
    }

    void build(int p){
      for(p >>= 1; p > 0; p >>= 1) tree[p] = tree[p << 1] ^ tree[p << 1 | 1];
    }

    void push(int p){
      for(int h = __lg(p); h > 0; h--){
        int cur = p >> h;
        if(lazy[cur] != 0){
          apply(cur << 1, lazy[cur]);
          apply(cur << 1 | 1, lazy[cur]);
          lazy[cur] = 0;
        }
      }
    }

  public:
    LazySegmentTree(vector<T> &a): n(a.size()){
      tree = new T[n << 1]();
      lazy = new T[n << 1]();
      init(a);
    }

    void update_range(int l, int r, T val){
      for(int L = l + n, R = r + n; L < R; L >>= 1, R >>= 1){
        if(L & 1) apply(L++, val);
        if(R & 1) apply(--R, val);
      }
      build(l + n);
      build(r + n - 1);
    }

    T getVal(int p){
      push(p += n);
      return tree[p];
    }
};

int n, m;

int main() {
  fastio(nullptr, false);

  cin >> n;
  vi a(n);
  for(auto &x : a) cin >> x;
  
  LazySegmentTree<int> lazySeg(a);

  cin >> m;
  while(m--){
    int t, x, y, z;
    cin >> t >> x;

    if(t & 1){
      cin >> y >> z;
      lazySeg.update_range(x, y+1, z);
      continue;
    }

    cout << lazySeg.getVal(x) << nl;
  }
}