#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
int n, m, a, b;
vector<int> adj[32001];
int deg[32001]; // deg[i] : i 정점의 indegree 개수
void topological_sort(vector<int> &v){
  queue<int> q;
  for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    v.push_back(cur);
    for(int nxt : adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    deg[b]++;
  }
  vector<int> ans;
  topological_sort(ans);
  for(int v : ans) cout << v << ' ';
}