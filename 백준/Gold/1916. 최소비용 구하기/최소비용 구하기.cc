#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

const ll inf = 1e15;
vpl adj[1005];
ll dist[1005];

int n, m, st, en;

int main() {
  fastio(nullptr, false);
  
  // input
  cin >> n >> m;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({w, v});
  }
  cin >> st >> en;

  // init
  priority_queue<pl, vpl, greater<pl>> pq;
  fill(dist, dist+n+1, inf);
  dist[st] = 0;
  pq.push({dist[st], st});

  // dijkstra
  while(sz(pq)){
    auto cur = pq.top(); pq.pop();
    if(dist[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
      dist[nxt.Y] = dist[cur.Y] + nxt.X;
      pq.push({dist[nxt.Y], nxt.Y});
    }
  }

  // output
  cout << dist[en];
}