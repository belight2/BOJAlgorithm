#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
int n, m, u, v, w;
int d[205][205];
int nxt[205][205];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(&d[0][0], &d[n+1][n+1], INF);
  while(m--){
    cin >> u >> v >> w;
    d[u][v] = w;
    d[v][u] = w;
    nxt[u][v] = v;
    nxt[v][u] = u;
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(d[i][j] > d[i][k] + d[k][j]){
          d[i][j] = d[i][k] + d[k][j];
          nxt[i][j] = nxt[i][k];
        }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++)
      if(nxt[i][j] == 0) cout << "- ";
      else cout << nxt[i][j] << ' ';
    cout << nl;
  }
}