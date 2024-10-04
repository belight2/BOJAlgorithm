#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define long2(x) int(log10(x)/log10(2)) + 2;
using namespace std;
const char nl = '\n';
const int MX = 100005;
const int MK = log2(MX);
int n, m, u, v;
vector<int> adj[MX];
int p[MK][MX];
int d[MX];
vector<bool> chk(MX);
void dfs(int cur){
  for (int nxt : adj[cur]) {
    if(chk[nxt]) continue;
    p[0][nxt] = cur;
    d[nxt] = d[cur] + 1;
    chk[nxt] = 1;
    dfs(nxt);
  }
}
int LCA(int u, int v){
  if(d[u] < d[v]) swap(u, v);
  int diff = d[u] - d[v];
  for(int i = MK-1; i >= 0; i--)
    if(diff&(1 << i)) u = p[i][u];
  if(u == v) return u;
  for(int i = MK-1; i >= 0; i--){
    if(p[i][u] > 0 && p[i][u] != p[i][v]){
      u = p[i][u];
      v = p[i][v];
    }
  }
  return p[0][u];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int t = n - 1;
  while(t--){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  p[0][1] = -1;
  d[1] = 1;
  chk[1] = 1;
  dfs(1);
  for(int i = 1; i < MK; i++)
    for(int j = 1; j <= n; j++)
      p[i][j] = p[i-1][j] > 0 ? p[i-1][p[i-1][j]] : -1; 
  cin >> m;
  while(m--){
    cin >> u >> v;
    cout << LCA(u, v) << nl;
  }
}