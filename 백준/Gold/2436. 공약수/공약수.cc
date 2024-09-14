// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define X first
#define Y second
pair<ll, ll> ans;
ll G, L;


int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> G >> L;

  // solve
  ll div = L / G;
  for(ll cur = 1; cur * cur <= div; cur++){
    if(div % cur || gcd(cur, div/cur) != 1) continue;
    ans = { cur*G, (div/cur)*G };
  }

  // output
  cout << ans.X << ' ' << ans.Y;
}