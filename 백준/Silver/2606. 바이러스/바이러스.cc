#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const char nl = '\n';
vector<int> adj[105];
vector<bool> vis(105);
int ans;
int N, M, u, v;
void dfs(){
  stack<int> stk;
  stk.push(1);
  vis[1] = 1;
  while(!stk.empty()){
    auto cur = stk.top(); stk.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      ans++;
      vis[nxt] = 1;
      stk.push(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  while(M--){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs();
  cout << ans;
}