#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const char nl = '\n';
int n;
int a, b, t;
int d[25][25];
vector<vector<bool>> u(25, vector<bool>(25, 0));
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> d[i][j];
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      bool isunit = 1;
      for(int k = 1; k <= n; k++){
        if(k == i || k == j) continue;
        int tmp = d[i][k] + d[k][j];
        if(tmp < d[i][j]){ cout << -1; return 0;}
        else if(tmp == d[i][j]) isunit = 0;
      }
      if(isunit) u[i][j] = u[j][i] = 1;
    }
  
  int ans = 0;
  for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++)
      if(u[i][j]) ans += d[i][j];
  cout << ans;
}