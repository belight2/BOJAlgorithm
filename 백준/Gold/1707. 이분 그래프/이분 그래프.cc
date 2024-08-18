#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
int t;
void solve(){
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> vis(n+1, 0);
  queue<int> q;
  while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    if(vis[i] != 0) continue;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()){
      auto cur = q.front(); q.pop();
      for(auto nxt : adj[cur]){
        if(vis[nxt] != 0){
          if(vis[nxt] == vis[cur]){
            cout << "NO" << nl; return;
          }
          else continue;
        }
        vis[nxt] = vis[cur] * -1;
        q.push(nxt);
      }
    }
  }
  cout << "YES" << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) solve();
}