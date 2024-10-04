#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pi = pair<ll,int>;
using ti = tuple<ll,int,int>;
const char nl = '\n';
const ll INF = 1e10+10;
int n, m, k, u, v;
ll c;
vector<pi> adj[100005];
ll d[100'005];
vector<int> dest;
void dijkstra(){
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  for(int cur : dest){
    d[cur] = 0;
    pq.push({0, cur});
  }
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
  cin >> n >> m >> k;
  while(m--){
    cin >> u >> v >> c;
    adj[v].pb({c, u});
  }
  fill(d, d+n+1, INF);
  while(k--){
    cin >> u;
    dest.pb(u);
  }
  dijkstra();
  ll ans = *max_element(d+1, d+n+1);
  for(int i = 1; i <= n; i++) if(d[i] == ans) {cout << i << nl; break;}
  cout << ans;
}