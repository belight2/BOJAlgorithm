#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const char nl = '\n';
int n, m;
vector<int> adj[100'001];
int p[100'005];
int w[100'005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> p[1];
  for(int i = 2; i <= n; i++){
    cin >> p[i];
    adj[i].push_back(p[i]);
    adj[p[i]].push_back(i);
  }
  int x, y;
  while(m--){
    cin >> x >> y;
    w[x] += y;
  }
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(nxt == p[cur]) continue;
      w[nxt] += w[cur];
      q.push(nxt);
    }
  }
  for(int i = 1; i <= n; i++) cout << w[i] << ' ';
}