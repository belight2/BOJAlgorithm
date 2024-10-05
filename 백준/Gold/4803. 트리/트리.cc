#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
int n, m;
int tc = 1;
void solve(){
  vector<vector<int>> adj(n+1);
  vector<int> p(n+1);
  int u, v;
  while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(p[i]) continue;
    bool isTree = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      auto cur = q.front(); q.pop();
      for(auto nxt : adj[cur]){
        if(p[cur] == nxt) continue;
        if(p[nxt]){
          isTree = 0;
          continue;
        }
        p[nxt] = cur;
        q.push(nxt);
      }
    }
    ans += isTree;
  }
  cout << "Case " << tc++ <<": ";
  if(ans == 0) cout << "No trees.\n";
  else if(ans == 1) cout << "There is one tree.\n";
  else cout << "A forest of " << ans << " trees.\n"; 
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    cin >> n >> m;
    if(n == 0) break;
    solve();
  }
}