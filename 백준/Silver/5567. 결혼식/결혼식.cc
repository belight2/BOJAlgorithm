#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const char nl = '\n';
vector<int> adj[502];
vector<bool> vis(502);
int n, m, a, b, ans;
void dfs(){
  stack<int> stk;
  stk.push(1);
  vis[1] = 1;
  while(!stk.empty()){
    auto cur = stk.top(); stk.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      ans++;
      if(cur == 1) stk.push(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  cout << ans;
}