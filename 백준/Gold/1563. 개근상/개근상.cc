#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
const int MOD = 1e6;
int n;
int d[1005][5][5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  d[1][0][0] = 1;
  d[1][1][0] = 1;
  d[1][0][1] = 1;

  for(int i = 2; i <= n; i++){
    d[i][0][0] = (d[i-1][0][0] + d[i-1][0][1] + d[i-1][0][2]) % MOD;
    d[i][0][1] = d[i-1][0][0] % MOD;
    d[i][0][2] = d[i-1][0][1] % MOD;
    d[i][1][0] = (d[i-1][0][0] + d[i-1][0][1] + d[i-1][0][2] + d[i-1][1][0] + d[i-1][1][1] + d[i-1][1][2]) %MOD;
    d[i][1][1] = d[i-1][1][0] % MOD;
    d[i][1][2] = d[i-1][1][1] % MOD;
  }
  cout << (d[n][0][0] + d[n][0][1] + d[n][0][2] + d[n][1][0] + d[n][1][1] + d[n][1][2] ) % MOD;
}