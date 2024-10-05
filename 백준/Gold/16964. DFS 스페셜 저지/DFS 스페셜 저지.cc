#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
int n, u, v, x, cnt;
bool vis[100005];
vector<int> adj[100005];
vector<int> idx;
bool cmp(const int &x, const int &y){
  return idx[x] < idx[y];
}
bool dfs(int cur){
  vis[cur] = 1;
  if(cnt != idx[cur]) return 0;
  cnt++;
  sort(all(adj[cur]), cmp);
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    return dfs(nxt);
  }
  return cnt-1 == idx[cur];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  idx.resize(n+1);
  for(int i = 0; i < n; i++){
    cin >> x;
    idx[x] = i;
  }
  cout << dfs(1);
}