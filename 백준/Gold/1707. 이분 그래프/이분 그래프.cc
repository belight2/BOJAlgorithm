#include <bits/stdc++.h>

using namespace std;

int t, n, m, u, v;

vector<int> adj[20'005];
vector<int> vis;

bool bfs(int st){
  queue<int> q;
  vis[st] = 1;
  q.push(st);
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt] == vis[cur]) return 1;
      if(vis[nxt] != 0) continue;
      vis[nxt] = -vis[cur];
      q.push(nxt);
    }
  }
  return 0;
}

void solve(){
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++) vector<int> ().swap(adj[i]);
  vector<int> ().swap(vis);
  vis.resize(n+1);

  while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  bool ans{};
  for(int i = 1; i <= n; i++){
    if(vis[i] != 0) continue;
    if(ans = bfs(i)) break;
  }
  
  cout << (ans ? "NO" : "YES") << '\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false); 
  cin >> t;
  while(t--) solve();
}