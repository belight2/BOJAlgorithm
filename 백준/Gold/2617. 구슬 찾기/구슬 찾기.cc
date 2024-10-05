// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> h[101], l[101];
bool vis[101];

bool solve(int st, vector<int> (&adj)[]){
  // init
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  int cnt{};

  // bfs
  q.push(st);
  vis[st] = 1;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      cnt++;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }

  return cnt >= (n+1)/2;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    h[u].push_back(v);
    l[v].push_back(u);
  }

  // solve
  int ans{};
  for(int i = 1; i <= n; i++){
    ans += (solve(i, h) || solve(i, l));
  }

  // output
  cout << ans;
}