// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

const int MX = 100'005;
const int MK = 33 - __builtin_clz(MX);

int n;
vector<int> adj[MX];
vector<bool> vis(MX);
int d[MX];

int p[MK][MX];

void dfs(int cur){
  vis[cur] = 1;
  for(int nxt : adj[cur]){
    if(vis[nxt]) continue;
    p[0][nxt] = cur;
    d[nxt] = d[cur] + 1;
    dfs(nxt);
  }
}

int LCA(int u, int v){
  if(d[u] < d[v]) swap(u, v); // depth가 더 높은 값을 u로 변경
  
  // 정점 u의 depth를 v와 맞춰주는 작업
  int diff = d[u] - d[v];
  for(int i = MK - 1; i >= 0; i--){
    if(diff & (1 << i)){
      u = p[i][u];
    }
  }

  // depth를 맞췄더니 서로 같은 값, LCA가 v였음.
  if(u == v) return u;

  // u, v의 depth를 같이 내리면서 LCA 찾기
  for(int i = MK - 1; i >= 0; i--){
    // 2^i번 거슬러 올라갈 수 있고, 올라갔을 때, 서로 같은 값이 아님(이 조건을 넣지 않으면 루트 노드로 거슬러 올라감)
    if(p[i][u] > 0 && p[i][u] != p[i][v]){
      u = p[i][u];
      v = p[i][v];
    }
  }

  // LCA 반환
  return p[0][u];
}

void solve(){
  // input * init
  cin >> n;  
  
  for(int i = 1; i <= n; i++) adj[i].clear();
  fill(vis.begin(), vis.end(), 0);
  memset(p, 0, sizeof(p));
  memset(d, 0, sizeof(d));

  int t = n - 1;
  vector<bool> isroot(n+1, 1);
  while(t--){
    int u, v;
    cin >> u >> v;
    isroot[v] = 0;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int root = find(isroot.begin() + 1, isroot.end(), 1) - isroot.begin();
  d[root] = 1;
  p[0][root] = -1;
  dfs(root);

  for(int i = 1; i < MK; i++){
    for(int j = 1; j <= n; j++){
      p[i][j] = p[i-1][j] > 0 ? p[i-1][p[i-1][j]] : -1;
    }
  }

  // output
  int u, v;
  cin >> u >> v;
  cout << LCA(u, v) << '\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}