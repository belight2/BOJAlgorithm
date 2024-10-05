#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
ll n, p, q;
unordered_map<ll, ll> a;
ll solve(ll x){
  if(x == 0 || a.find(x) != a.end()) return a[x];
  a[x] = solve(x/p) + solve(x/q);
  return a[x];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p >> q;
  a[0] = 1;
  cout << solve(n);
}