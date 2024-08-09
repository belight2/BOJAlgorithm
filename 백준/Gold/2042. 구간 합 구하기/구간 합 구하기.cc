#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename T>
class SegmentTree{
  private:
    T *Tree;
    int N;
  public:
    SegmentTree(vector<T> &A){
      N = A.size();
      Tree = new T[N * 2];
      for(int i = 0; i < N; i++) Tree[N+i] = A[i];
      for(int i = N-1; i > 0; --i) Tree[i] = Tree[i<<1] + Tree[i<<1 | 1];
    }
    ~SegmentTree(){ delete [] Tree; }
    void update(int p, T value){
      Tree[p+N] = value;
      p = p + N;

      for(int i = p; i > 1; i >>= 1) Tree[i>>1] = Tree[i]+Tree[i^1];
    }
    T sum(int l, int r){
      T ret{};
      for( l += N, r += N; l < r; l >>= 1, r >>= 1){
        if(l&1) ret += Tree[l++];
        if(r&1) ret += Tree[--r];
      }
      return ret;
    }
};

int n, m, k;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  vector<ll> a(n);
  for(auto &x : a) cin >> x;
  SegmentTree<ll> ST(a);
  m += k;
  while(m--){
    ll a, b, c;
    cin >> a >> b >> c;
    if(a&1) ST.update(b-1, c);
    else cout << ST.sum(b-1, c) << '\n';
  }
}