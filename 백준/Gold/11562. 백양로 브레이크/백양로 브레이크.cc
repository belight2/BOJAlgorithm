#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const char nl = '\n';
const int INF = 1'000'000;
int d[255][255];
int n, m, u, v, b, k, s, e;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) fill(d[i], d[i]+1+n, INF);
  // 최단 거리가 아닌,
  // 양방향 길로 바꾸는 최소 횟수에 대해서 기록하고 싶음
  while(m--){
    cin >> u >> v >> b;
    d[u][v] = 0;
    d[v][u] = !b;
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;
  for(k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(d[i][j] > d[i][k] + d[k][j]){
          d[i][j] = d[i][k] + d[k][j];
        }
  cin >> k;
  while(k--){
    cin >> s >> e;
    cout << d[s][e] << nl;
  }
}