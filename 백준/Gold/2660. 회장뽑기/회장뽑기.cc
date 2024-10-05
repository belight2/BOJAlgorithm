// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[55];
int dist[55][55];
int score[55];

int bfs(int st){
  queue<int> q;
  q.push(st);
  dist[st][st] = 0;
  
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(dist[st][nxt] != -1) continue;
      dist[st][nxt] = dist[st][cur] + 1;
      q.push(nxt);
    }
  }

  int ret = *max_element(dist[st], dist[st]+n+1);
  return (ret == 0 ? 100 : ret);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  int u, v;
  while(cin >> u >> v, u != -1){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // solve
  memset(dist, -1, sizeof(dist));
  for(int i = 1; i <= n; i++){
    score[i] = bfs(i);
  }

  int mnsc = *min_element(score+1, score+n+1);
  vector<int> ans;
  for(int i = 1; i <= n; i++){
    if(score[i] == mnsc)
      ans.push_back(i);
  }

  // output
  cout << mnsc << ' ' << ans.size() << '\n';
  for(auto x : ans) cout << x << ' ';
}