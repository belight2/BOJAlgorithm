#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const char nl = '\n';
int n, m, u, v;
vector<int> adj[100'005];
vector<bool> vis(100'005);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int group = 0;
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    group++;
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()){
      auto cur = q.front(); q.pop();
      for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = 1;
      }
    }
  }
  cout << group - 1 + abs(m+group-n);
}