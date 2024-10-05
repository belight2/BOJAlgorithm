#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
vector<pair<int,int>> adj[1'000];
int dist[1'005][1'005];
int n, m, u, v, w;
int root;
void dfs(int cur, int prv){
  int vertex, weight;
  for(auto nxt : adj[cur]){
    if(nxt.X == prv) continue;
    dist[root][nxt.X] = dist[root][cur] + nxt.Y;
    dfs(nxt.X, cur);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n - 1; i++){
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for(int i = 1; i <= n; i++){
   root = i;
   dfs(i , -1); 
  }
  while(m--){
    cin >> u >> v;
    cout << dist[u][v] << nl;
  }
}