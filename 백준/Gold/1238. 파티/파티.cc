#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
vector<pi> adj[1005];
int n, m, x, u, v, w;
int d[1005][1005];
void dijkstra(int st, int d[]){
  priority_queue<pi, vector<pi>, greater<pi>> pq;
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
  cin >> n >> m >> x;
  for(int i = 1; i <= n; i++) fill(d[i], d[i]+1+n, INF);
  while(m--){
    cin >> u >> v >> w;
    adj[u].pb({w, v});
  }
  for(int i = 1; i <= n; i++) dijkstra(i, d[i]);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans = max(ans, d[i][x] + d[x][i]);
  }
  cout << ans;
}