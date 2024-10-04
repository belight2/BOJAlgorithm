#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const char nl = '\n';
int n, m, a, b;
vector<int> adj[32005];
int deg[32005];
void topological_sort(vector<int> &ans){
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 1; i <= n; i++) if(!deg[i]) pq.push(i);
  while(!pq.empty()){
    int cur = pq.top(); pq.pop();
    ans.push_back(cur);
    for(int nxt : adj[cur]) if(!(--deg[nxt])) pq.push(nxt);
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