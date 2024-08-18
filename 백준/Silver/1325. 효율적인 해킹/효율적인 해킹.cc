#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
vector<int> adj[10005];

int ret;
int hacked[10005];
int vis[10005];
int state{};

void dfs(int cur){
  vis[cur] = state;
  for(auto nxt : adj[cur]){
    if(vis[nxt] == state) continue;
    dfs(nxt);
    ret++;
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;

  while(m--){
    cin >> u >> v;
    adj[v].push_back(u);
  }
  
  for(int i = 1; i <= n; i++){
    state++;
    ret = 1;
    dfs(i);
    hacked[i] = ret;
  }

  int mx = *max_element(hacked, hacked+n+1);
  for(int i = 1; i <= n; i++) if(mx == hacked[i]) cout << i << ' ';
}