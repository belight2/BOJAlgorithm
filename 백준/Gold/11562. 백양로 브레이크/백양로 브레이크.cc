// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  길이 있고 지날 수 있는 방향 비용은 0
  길이 있는데 지날 수 없는 방향 비용은 1

  위와 같이 인접 행렬에 플로이드 알고리즘을 사용하면

  u -> v로 이동할 때, 양방향 통행으로 바꿔야 할 최소 횟수를 구할 수 있다.
*/
using namespace std;

const int INF = 1e6;

int n, m, k;
int d[255][255];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input & init
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++){
    fill(d[i], d[i] + n + 1, INF);
    d[i][i] = 0;
  }

  // 최단 거리가 아닌 양방향 길로 바꾸는 최소 횟수에 대해서 기록하고 싶음.
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    
    d[u][v] = 0;
    d[v][u] = !w;
  }

  // solve
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  // output
  cin >> k;
  while(k--){
    int s, e;
    cin >> s >> e;
    cout << d[s][e] << '\n';
  }
}