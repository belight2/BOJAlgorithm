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

int n, m, x, y;
vi adj[500'005];
vpl cost;
ll security[500'005];
queue<int> q;

int main() {
  fastio(nullptr, false);

  cin >> n >> m >> x >> y;
  for(int i = 1; i <= n; i++){
    int c;
    cin >> c;
    cost.pb({c, i});
  }
  
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(int i = 0; i < y; i++){
    int u;
    cin >> u;
    security[u] = 1;
    q.push(u);
  }

  while(q.size()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(security[nxt] != 0 && security[nxt] <= security[cur] + 1) continue;
      security[nxt] = security[cur] + 1;
      q.push(nxt);
    }
  }

  for(auto &cur : cost){
    auto &[c, v] = cur;
    if(!security[v] && c){
      cout << -1;
      return 0;
    }
    c *= security[v]-1;
  }

  ll ans{};
  sort(rall(cost));
  for(int i = 0; i < x; i++){
    ans += cost[i].X;
  }
  cout << ans;
}