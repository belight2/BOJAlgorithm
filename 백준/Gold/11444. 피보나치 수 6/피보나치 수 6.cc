#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pl = pair<ll, ll>;
const char nl = '\n';
const ll MOD = 1e9+7;
pl rpow(ll n){
  if(n==1) return {1, 0};
  ll x, y; tie(x, y) = rpow(n/2);
  pl ret = { x* (x +2*y) % MOD, (x*x + y*y)%MOD};
  if(n&1) ret = {(ret.X + ret.Y)%MOD, ret.X};
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n{};
  cin >> n;
  cout << rpow(n).X;
}