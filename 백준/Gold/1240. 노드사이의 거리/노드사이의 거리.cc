// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

int n, m;
vector<pi> adj[1005];
int dist[1005][1005];

void dfs(int prv, int cur, int root){
  for(auto &[nxt, weight] : adj[cur]){
    if(nxt == prv) continue;
    dist[root][nxt] = dist[root][cur] + weight;
    dfs(cur, nxt, root);
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n - 1; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  // solve
  for(int i = 1; i <= n; i++) dfs(-1, i, i);
  
  // output
  while(m--){
    int u, v;
    cin >> u >> v;
    cout << dist[u][v] << '\n';
  }
}