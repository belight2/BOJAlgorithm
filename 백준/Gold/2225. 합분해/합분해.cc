#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 1'000'000'000
using namespace std;
const char nl = '\n';
int n, k;
ll d[205][205];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  fill(d[1], d[1]+n+1, 1);
  for(int i = 2; i <= k; i++){
    for(int j = 0; j <= n; j++){
      for(int k = j; k <= n; k++){
        d[i][k] = (d[i][k] + d[i-1][k-j])%mod;
      }
    }
  }
  cout << d[k][n];
}