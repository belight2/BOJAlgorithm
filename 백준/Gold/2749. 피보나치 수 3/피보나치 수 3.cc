#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
const char nl = '\n';
int MOD = 1e6;
ll f[1500001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n{}; cin >> n;
  n %= 15 * int(1e5);
  f[0] = 0; f[1] = 1;
  for(int i = 2; i <= n; i++){
    f[i] = (f[i-1] + f[i-2]) % MOD;
  }
  cout << f[n];
}