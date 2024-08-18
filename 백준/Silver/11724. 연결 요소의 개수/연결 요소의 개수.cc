#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
vector<int> adj[1001];
vector<bool> vis(1001);

void bfs(int st){
  queue<int> q;
  vis[st] = 1;
  q.push(st);

  while(q.size()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }
}
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;
  
  while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans{};
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    ans++;
    bfs(i);
  }
  
  cout << ans;
}