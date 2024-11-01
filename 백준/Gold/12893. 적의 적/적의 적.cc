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

int n, m;
vi adj[2005];
int vis[2005];

bool bfs(int cur){
  qi q;  
  vis[cur] = 1;
  q.push(cur);

  while(sz(q)){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt] == vis[cur]) return 0;
      if(vis[nxt] != 0) continue;
      q.push(nxt);
      vis[nxt] = -vis[cur];
    }
  }
  return 1;
}

int main() {
  fastio(nullptr, false);

  cin >> n >> m;

  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  bool ans = 0;
  for(int i = 1; i <= n; i++){
    if(vis[i] != 0) continue;
    if(!(ans = bfs(i))) break;
  }
  cout << ans;
}