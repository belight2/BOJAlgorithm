#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
const int INF = 1e9+10;
vector<pair<int,int>> adj[1005];
int d[1005], pre[1005];
int n, m, u, v, w;
int st, en;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(d, d+n+1, INF);
  while(m--){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  cin >> st >> en;
  priority_queue<pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>> pq;
  d[st] = 0;
  pq.push({d[st], st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X ) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y], nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }
  cout << d[en] << nl;
  vector<int> path;
  while(en != st){
    path.push_back(en);
    en = pre[en];
  }
  path.push_back(st);
  cout << path.size() << nl;
  for(auto i = path.rbegin(); i < path.rend(); i++) cout << *i << ' ';
}