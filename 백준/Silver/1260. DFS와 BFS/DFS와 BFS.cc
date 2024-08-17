#include <bits/stdc++.h>

using namespace std;

int n, m, st, u, v;
vector<int> adj[1001];
bool vis[1001];

void dfs(int cur){
  vis[cur] = 1;
  cout << cur << " ";

  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

void bfs(int st){
  queue<int> q;
  q.push(st);
  vis[st] = 1;

  while(q.size()){
    auto cur = q.front(); q.pop();
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m >> st;
  
  while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  
  dfs(st);

  memset(vis, 0, sizeof(vis));
  cout << "\n";

  bfs(st);
}