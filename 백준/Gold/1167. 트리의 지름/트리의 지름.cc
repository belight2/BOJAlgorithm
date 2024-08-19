#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

int n, u, v, w;
vector<pi> adj[100'005];
int dist[100'005];

int bfs(int st){
  fill(dist, dist+n+1, -1);
  queue<int> q;
  dist[st] = 0;
  q.push(st);

  while(q.size()){
    auto cur = q.front(); q.pop();  
    for(auto nxt : adj[cur]){
      if(dist[nxt.Y] != -1) continue;
      dist[nxt.Y] = dist[cur] + nxt.X;
      q.push(nxt.Y);
    }
  }
  
  return max_element(dist, dist+n+1) - dist;
}
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> u;
    while(cin >> v, v != -1){
      cin >> w;
      adj[u].push_back({w, v});
    }
  }

  cout << dist[bfs(bfs(1))];
}