#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int d[25][2][105];
string mg;
string a[2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> mg >> a[0] >> a[1];
  int n = mg.size();
  int m = a[0].size();
  for(int i = 0; i < m; i++){
    d[0][0][i] = (a[0][i] == mg[0]) ? d[0][0][max(i-1, 0)] + 1 : d[0][0][max(i-1, 0)];
    d[0][1][i] = (a[1][i] == mg[0]) ? d[0][1][max(i-1, 0)] + 1 : d[0][1][max(i-1, 0)];
  }
  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      d[i][0][j] = (a[0][j] == mg[i]) ? d[i][0][j-1] + d[i-1][1][j-1] : d[i][0][j-1];
      d[i][1][j] = (a[1][j] == mg[i]) ? d[i][1][j-1] + d[i-1][0][j-1] : d[i][1][j-1];
    }
  }
  cout << d[n-1][0][m-1] + d[n-1][1][m-1] << nl;
}