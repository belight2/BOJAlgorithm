#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const char nl = '\n';
int n, m;
vector<int> adj[1001];
int deg[1001];
void topological_sort(vector<int> & v){
  queue<int> q;
  for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    v.push_back(cur);
    for(int nxt : adj[cur]) if(!(--deg[nxt])) q.push(nxt);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    int s, cur, nxt;
    cin >> s >> cur;
    for(int i = 1; i < s; i++){
      cin >> nxt;
      adj[cur].push_back(nxt);
      deg[nxt]++;
      cur = nxt;
    }
  }
  vector<int> res;
  topological_sort(res);
  if(res.size() != n) cout << 0;
  else for(int v : res) cout << v << nl;
}