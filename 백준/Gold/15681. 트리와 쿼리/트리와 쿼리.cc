#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
int n, root, query, u, v;
int ans[100'005];
vector<int> adj[100'005];
void dfs(int cur, int prv){
  if(adj[cur].size() == 1 && adj[cur][0] == prv){
    ans[cur] = 1; return;
  }
  for(auto nxt : adj[cur]){
    if(nxt == prv) continue;
    if(!ans[nxt]) dfs(nxt, cur);
    ans[cur] += ans[nxt];
  }
  ans[cur]++;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> root >> query;
  n--;
  while(n--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(root, -1);
  while(query--){
    cin >> root;
    cout << ans[root] << nl;
  }
}