#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pl = pair<ll, ll>;
const char nl = '\n';
const ll mod = 1e9;
int n;
pl rpow(int n){
  if(n==1) return { 1, 0 };
  ll x, y; tie(x, y) = rpow(n/2);
  pl res = {x*(x+2*y)%mod, (x*x + y*y)%mod};
  if(n&1) res = {(res.X + res.Y)%mod, res.X};
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  if(!n){ cout << "0\n0"; return 0; }
  ll ans = rpow(abs(n)).X;
  int sign = (n < 0 && abs(n) % 2 == 0) ? -1 : 1;
  cout << sign << nl << ans;
}