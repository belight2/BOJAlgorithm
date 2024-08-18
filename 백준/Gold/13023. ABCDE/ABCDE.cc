#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<int> adj[2005];
bool vis[2005];

bool dfs(int cur, int dep){
  if(dep == 4) return 1;
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    if(dfs(nxt, dep+1)) return 1;
    vis[nxt] = 0;
  }
  return 0;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;

  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bool ans{};
  for(int i = 1; i <= n; i++){
    vis[i] = 1;
    if(ans = dfs(i, 0)) break;
    vis[i] = 0;
  }

  cout << ans;
}