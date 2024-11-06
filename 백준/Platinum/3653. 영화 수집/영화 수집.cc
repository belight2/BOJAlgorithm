#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
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

int n, m;

template<typename T>
class SegmentTree{
  private:
    int N;
  public:
    T *tree;
    SegmentTree(vector<T> &A){
      N = A.size();
      tree = new T[N * 2];
      for(int i = 0; i < N; i++) tree[N + i] = A[i];
      for(int i = N - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    ~SegmentTree(){ delete [] tree; }

    void update(int p, T value){
      p += N;
      tree[p] = value;
      for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    T sum(int l, int r){
      T ret{};
      for( l += N, r += N; l < r; l >>= 1, r >>= 1){
        if(l & 1) ret += tree[l++];
        if(r & 1) ret += tree[--r];
      }
      return ret;
    }
};

void solve(){
  // input
  cin >> n >> m;
  
  // init
  vi idx;
  for(int i = n; i >= 0; i--) idx.pb(i);
  
  vector<int> a;
  for(int i = 0; i < n; i++) a.pb(1);
  for(int i = 0; i < m; i++) a.pb(0);

  SegmentTree<int> seg(a);

  int offset = n;
  while(m--){
    int x; cin >> x;    

    cout << seg.sum(idx[x]+1, a.size()) << ' ';

    seg.update(idx[x], 0);
    idx[x] = offset++;
    seg.update(idx[x], 1);
  }
  cout << nl;
}

int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}