#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll aC2(ll a){ return a * (a-1) / 2; }

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n{}, m{};
  cin >> n >> m;

  vector<ll> a(n+1);
  vector<ll> b(m);

  for(int i = 1; i <= n; i++) cin >> a[i];
  
  ll ans{}, sum{};
  for(int i = 1; i <= n; i++){
    sum = (sum + a[i]) % m;
    if(!sum) ans++;
    b[sum]++;
  }
  for(int i = 0; i < m; i++) ans += aC2(b[i]);
  
  cout << ans;
}