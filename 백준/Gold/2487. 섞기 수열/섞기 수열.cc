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

int n;
vi adj[20'005];
vb vis(20'005);

ll bfs(int cur){
  ll edge_count = 1; 
  qi q; 
  vis[cur] = 1;
  q.push(cur);
  while(sz(q)){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      q.push(nxt);
      edge_count++;
    }
  } 
  return edge_count;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int cur = 1; cur <= n; cur++){
    int nxt; cin >> nxt;
    adj[cur].pb(nxt);
  }

  // solve
  vl cycle;
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    cycle.pb(bfs(i));
  }

  ll ans = cycle[0];
  for(int i = 1; i < sz(cycle); i++){
    ans = lcm(ans, cycle[i]);
  }

  // output
  cout << ans;
}