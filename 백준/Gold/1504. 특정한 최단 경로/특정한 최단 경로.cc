#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
const int INF = 1e8+10;
int n, e, a, b, c;
int u, v;
vector<pi> adj[805];
int d[805][805];
void dijstra(int st, int d[]){
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  fill(d, d+n+1, INF);
  d[st] = 0;
  pq.push({d[st], st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> e;
  while(e--){
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  cin >> u >> v;
  dijstra(1, d[1]);
  dijstra(u, d[u]);
  dijstra(v, d[v]);
  int ans = min(d[1][u] + d[u][v] + d[v][n], d[1][v]+d[v][u]+d[u][n]);
  if(ans >= INF) cout << -1;
  else cout << ans;
}