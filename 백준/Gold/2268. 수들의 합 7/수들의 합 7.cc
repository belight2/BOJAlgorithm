// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
ll tree[2'000'005]; // 세그먼트 트리
 
void modify(int p, ll value){
  p += n;
  tree[p] = value;
  for(int i = p; i > 1; i >>= 1) tree[i >> 1] = tree[i] + tree[i ^ 1];
}

ll sum(int l, int r){
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
  
  // solve
  while(m--){
    ll cmd, a, b;
    cin >> cmd >> a >> b;
 
    if(cmd) modify(a-1, b);
    else cout << sum(min(a, b)-1, max(a, b)) << '\n';
  }
}