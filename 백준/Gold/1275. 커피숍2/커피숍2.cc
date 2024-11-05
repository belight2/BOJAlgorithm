// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
ll tree[200'005];

void update(int p, ll val){
  p += n;
  tree[p] = val;
  for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
}

ll sum_query(int l, int r){
  ll ret{};
  for(l += n, r += n; l < r; l >>= 1, r >>= 1){
    if(l & 1) ret += tree[l++];
    if(r & 1) ret += tree[--r];
  }
  return ret;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;  
  for(int i = 0; i < n; i++) cin >> tree[i + n];
  
  // init
  for(int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];

  // Query
  while(m--){
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if(x > y) swap(x, y);
    
    cout << sum_query(x-1, y) << '\n';
    update(a-1, b);
  }
}