#include <bits/stdc++.h>
using namespace std;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
const int INF = 1e10; // 무한대
int n; // 정점의 개수
int m; // 간선의 개수
vector<tuple<int,int,int>> edges; // 간선 정보 (u, v, w) : u -> v, w : 가중치
long long dist[505]; // 거리 테이블

bool bellman_ford(int st){
  // 거리 테이블 갱신
  fill(dist, dist+n+1, INF);
  dist[st] = 0;

  // n-1번 완화 반복
  for(int i = 0; i < n-1; i++){
    for(auto &edge : edges){
      auto &[u, v, cost] = edge;
      if(dist[u] != INF && dist[u] + cost < dist[v]){
        dist[v] = dist[u] + cost;
      }
    }
  }

  // n-th 완화(negative cycle 검사)
  for(auto &edge : edges){
    auto &[u, v, cost] = edge;
    if(dist[u] != INF && dist[u] + cost < dist[v]){
      return 0; // negative cycle이 있음
    }
  }
  return 1; // negative cycle이 없음
}
int main() {
  fastio(nullptr, false);
  cin >> n >> m;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  if(bellman_ford(1)){
    for(int i = 2; i <= n; i++){
      cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
  }
  else cout << -1;
}