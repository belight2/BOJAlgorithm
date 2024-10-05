#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const char nl = '\n';
const int INF = 300000;
int n, m, r, a, b, l;
int d[105][105];
int item[105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> r;
  for(int i = 1; i <= n; i++) fill(d[i], d[i]+1+n, INF);
  for(int i = 1; i <= n; i++) cin >> item[i];
  while(r--){
    cin >> a >> b >> l;
    d[a][b] = l;
    d[b][a] = l;
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int tmp = 0;
    for(int j = 1; j <= n; j++) if(d[i][j] <= m) tmp += item[j]; 
    ans = max(ans, tmp);
  }
  cout << ans;
}