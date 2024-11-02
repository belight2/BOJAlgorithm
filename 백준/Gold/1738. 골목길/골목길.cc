#include <bits/stdc++.h>
/*

*/
using namespace std;

using ti = tuple<int, int, int>;

const int INF = -1e8;

int n, m;
vector<int> adj[105];
bool vis[105];

vector<ti> edges;
int d[105];
int prv[105];

void dfs(int cur){
  vis[cur] = 1;
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;

    edges.push_back({u, v, w});
    adj[v].push_back(u);
  }

  // solve
  dfs(n);

  fill(d, d + n + 1, INF);

  bool isexist_path = 1;
  d[1] = 0;
  for(int i = 1; i <= n; i++){
    for(auto &[u, v, w] : edges){
      if(d[u] == INF || d[u] + w <= d[v]) continue;

      d[v] = d[u] + w;
      prv[v] = u;

      if(i == n && vis[v]) isexist_path = 0;
    }
  }

  if(!isexist_path){
    cout << -1;
    return 0;
  }

  vector<int> path;
  while(n != 1){
    path.push_back(n);
    n = prv[n];
  }
  path.push_back(1);

  reverse(path.begin(), path.end());
  for(auto cx : path) cout << cx << ' ';
}