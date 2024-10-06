// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  conneted component의 개수를 깊이 우선 탐색으로 셉니다 (= group)
  
  이 그룹들을 모두 연결하기 위해서 group - 1 개의 간선이 필요합니다.

  따라서 현재 구조에서는 m + group - 1개의 간선이 존재하게 됩니다.

  트리는 n-1개의 간선만 존재하므로 (m + group - 1) - (n - 1)개의 간선을 제거해야합니다.

  따라서 트리가 되기 위해 간선을 추가/삭제하는 연산의 최소는

  group - 1 + (m + group - 1) - (n - 1)회가 됩니다.
*/
using namespace std;

int n, m;
vector<int> adj[100005];
vector<bool> vis(100005);

void dfs(int cur){
  vis[cur] = 1;
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;
    dfs(nxt);
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // solve
  int group{};
  for(int i = 1; i <= n; i++){
    if(vis[i]) continue;
    group++;
    dfs(i);
  }

  // output
  cout << (group - 1) + (m + group - 1) - (n - 1);
}