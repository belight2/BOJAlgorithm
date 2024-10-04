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
const ll INF = 1e18;
int n, st, en, m;
vti edges;
int cost[55];
int main() {
  fastio(nullptr, false);
  cin >> n >> st >> en >> m;
  while(m--){
    int s, e, w;
    cin >> s >> e >> w;
    edges.pb({s, e, w});
  }
  for(int i = 0; i < n; i++) cin >> cost[i];

  for(auto &cur : edges){
    auto &[u, v, w] = cur;
    w -= cost[v];
  }

  vl dist(n, INF);
  dist[st] = -cost[st];
  
  for(int i = 0; i < 2 * n; i++){
    for(auto &cur : edges){
      auto &[u, v, w] = cur;
      if(dist[u] != INF && dist[u] + w < dist[v]){
        dist[v] = (i < n-1) ? dist[u] + w : -INF;
      }
    }
  }
  if(abs(dist[en]) == INF){
    cout << (dist[en] == INF ? "gg" : "Gee");
  }
  else cout << -dist[en];
}