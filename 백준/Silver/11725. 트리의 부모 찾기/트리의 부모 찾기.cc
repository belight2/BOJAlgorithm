#include <bits/stdc++.h>

using namespace std;

int n, u, v;
vector<int> adj[100'005];
int p[100'005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n;
  for(int i = 1; i < n; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  queue<int> q;
  p[1] = -1;
  q.push(1);
  
  while(q.size()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(nxt == p[cur]) continue;
      p[nxt] = cur;
      q.push(nxt);
    }
  }

  for(int i = 2; i <= n; i++) cout << p[i] << '\n';
}