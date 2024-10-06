// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[55];
int deleted_node;

int dfs(int cur){
  // base condition
  if(adj[cur].size() == 0) return 1;

  int ret{};
  bool isleaf = 1;
  for(auto nxt : adj[cur]){
    if(nxt == deleted_node) continue;
    isleaf = 0;
    ret += dfs(nxt);
  }
  return (isleaf ? 1 : ret); 
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  int p, root;

  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> p;
    if(p == -1) root = i;
    else adj[p].push_back(i);
  }
  cin >> deleted_node;

  // solve
  int ans = (deleted_node == root ? 0 : dfs(root));

  // output
  cout << ans;
}