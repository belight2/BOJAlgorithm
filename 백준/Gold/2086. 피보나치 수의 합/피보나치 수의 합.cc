#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pl = pair<ll, ll>;
const char nl = '\n';
const ll MOD = 1e9;
ll a, b;
pl rpow(ll n){
  if(n==1) return {1, 0};
  ll x, y; tie(x, y) = rpow(n/2); 
  pl res{x * (x + 2 * y) % MOD, (x * x + y * y) %MOD};
  if(n&1) res = { ( res.X + res.Y ) % MOD, res.X };
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  cout << (rpow(b+2).X - rpow(a+1).X + MOD) % MOD;
}