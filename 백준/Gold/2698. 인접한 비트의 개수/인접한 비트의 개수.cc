#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
int t, n, k;
int d[105][105][2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  d[1][0][0] = 1;
  d[1][0][1] = 1;
  for(int i = 2; i <= 100; i++){
    for(int j = 0; j < i; j++){
      d[i][j][0] = d[i-1][j][0] + d[i-1][j][1];
      d[i][j][1] = d[i-1][j][0] + d[i-1][j-1][1];
    }
  }
  cin >> t;
  while(t--){
    cin >> n >> k;
    cout << d[n][k][0] + d[n][k][1] << nl;
  }
}