#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
vector<int> adj[1005];
bool vis[1005];

void dfs(int cur){
  vis[cur] = 1; 
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
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
    dfs(i);
  }

  cout << ans;
}