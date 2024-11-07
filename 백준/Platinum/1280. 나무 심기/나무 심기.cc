// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template<typename T>
class segment_tree{
  private:
    int n;
    T *tree;
  public:
    segment_tree(const vector<T> &a){
      n = a.size();
      tree = new T[2 * n];  
      for(int i = 0; i < n; i++) tree[i + n] = a[i];
      for(int i = n - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    
    ~segment_tree(){ delete [] tree; }

    void update(int p, T val){
      p += n;
      tree[p] += val;
      for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    T sum(int l, int r){
      T ret{};
      for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) ret += tree[l++];
        if(r & 1) ret += tree[--r];
      }
      return ret;
    }
};

const ll MOD = 1e9 + 7;
const int MX = 200'001;

int n, x;
segment_tree<ll> cnt(vector<ll> (200'005, 0));
segment_tree<ll> dist(vector<ll> (200'005, 0));

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> x;

  // init
  n--;
  cnt.update(x, 1);
  dist.update(x, x);

  // solve
  ll ans = 1;  
  while(n--){
    cin >> x;
    ll left = abs(dist.sum(0, x) - cnt.sum(0, x) * x) % MOD;
    ll right = abs(dist.sum(x+1, MX) - cnt.sum(x+1, MX) * x) % MOD;
    ans = (ans * (left + right) % MOD) % MOD;

    cnt.update(x, 1);
    dist.update(x, x);
  }  

  // output
  cout << ans;
}