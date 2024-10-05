// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using tl = tuple<ll, ll, ll>;

int n;
vector<tl> adj[10];
ll d[10];
bool vis[10];

void dfs(int cur){
  vis[cur] = 1;
  for(auto &[nxt, p, q] : adj[cur]){
    if(vis[nxt]) continue;
    d[nxt] = d[cur] / p * q;
    dfs(nxt);
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input
  cin >> n;
  ll init = 1;
  for(int i = 0; i < n-1; i++){
    int u, v, p, q;
    cin >> u >> v >> p >> q;
    init *= lcm(p, q);
    adj[u].push_back({v, p, q});
    adj[v].push_back({u, q, p});
  }

  // solve
  d[0] = init;
  dfs(0);
  
  ll tot_gcd = d[0];
  for(int i = 1; i < n; i++) tot_gcd = gcd(tot_gcd, d[i]);

  // output
  for(int i = 0; i < n; i++){
    cout << d[i] / tot_gcd << ' ';
  }
}