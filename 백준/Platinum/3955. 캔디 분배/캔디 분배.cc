// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using tl = tuple<ll, ll, ll>;

int n;

tl xGCD(ll a, ll b){
  if(!a) return {b, 0, 1};
  auto [g, x, y] = xGCD(b%a, a);
  return {g, y-(b/a)*x, x};
}

void solve(){
  ll k, c;
  cin >> k >> c;

  auto [g, x, y] = xGCD(k, c);
  
  ll ans{};
  if(k == 1 && c == 1) ans = 2;
  else if(c == 1) ans = k+1;
  else if(k == 1) ans = 1;
  else ans = (y+k)%k;

  if(g != 1 || ans > 1e9) cout << "IMPOSSIBLE\n";   
  else cout << ans << '\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  while(n--) solve();
}