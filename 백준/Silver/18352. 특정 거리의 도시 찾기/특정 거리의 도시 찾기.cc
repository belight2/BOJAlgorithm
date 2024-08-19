#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, u, v;
vector<int> adj[300'005];
int dist[300'005];
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m >> k >> x;
  
  while(m--){
    cin >> u >> v;
    adj[u].push_back(v);
  }

  queue<int> q;
  dist[x] = 1;
  q.push(x);
  
  while(q.size()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(dist[nxt] && dist[nxt] <= dist[cur]+1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  
  vector<int> ans;
  for(int i = 1; i <= n; i++) if(dist[i] == k+1) ans.push_back(i);
  if(ans.size()){
    for(auto res : ans) cout << res << '\n';
  }
  else cout << -1;
}