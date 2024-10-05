#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const char nl = '\n';
const int INF = 10'000'000;
int v, e;
int d[405][405];
int a, b, c;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e;
  for(int i = 1; i <= v; i++) fill(d[i], d[i]+v+1, INF);
  while(e--){
    cin >> a >> b >> c;
    d[a][b] = c;
  }
  for(int i = 1; i <= v; i++) d[i][i] = 0;
  for(int k = 1; k <= v; k++)
    for(int i = 1; i <= v; i++)
      for(int j = 1; j <= v; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int ans = INF;
  for(int i = 1; i < v; i++){
    for(int j = i+1; j <= v; j++){
      if(i == j) continue;
      ans = min(ans, d[i][j] + d[j][i]);
    }
  }
  if(ans == INF) cout << -1;
  else cout << ans;
}