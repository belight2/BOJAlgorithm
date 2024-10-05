#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using pll = pair<ll, ll>;
const char nl = '\n';
ll f[10005];
ll fibo(int n, ll mod){
    f[0] = 0%mod;
    f[1] = 1%mod;
    for(int i = 2; i <= n; i++)
      f[i] = (f[i-1]+f[i-2])%mod;
    return f[n];
}
void solve(int t){
  int n; ll mod;
  cin >> n >> mod;
  cout << "Case #" << t << ": " << fibo(n, mod) << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  for(int i = 1; i <= t; i++) solve(i);
}