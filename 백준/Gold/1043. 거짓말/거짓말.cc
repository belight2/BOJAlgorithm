#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
int n, m, s, p;
int adj[52][52];
vector<bool> pos(52, 1);
vector<int> party[52];
vector<int> truth;
void bfs(int x){
  queue<int> q;
  q.push(x);
  pos[x] = 0;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int nxt = 1; nxt <= n; nxt++){
      if(adj[cur][nxt] == 0 || !pos[nxt]) continue;
      q.push(nxt);
      pos[nxt] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> s;
  while(s--){
    cin >> p;
    truth.push_back(p);
  }
  for(int i = 0; i < m; i++){
    cin >> s;
    while(s--){
      cin >> p;
      party[i].push_back(p);
    }
    s = party[i].size();
    for(int j = 0; j < s-1; j++){
      for(int k = j+1; k < s; k++){
        adj[party[i][j]][party[i][k]] = 1;
        adj[party[i][k]][party[i][j]] = 1;
      }
    }
  }
  for(int x : truth) bfs(x);
  int ans = 0;
  for(int i = 0; i < m; i++){
    bool flag = true;
    for(int x : party[i]){
      if(pos[x]) continue;
      flag = false;
      break;
    }
    if(flag) ans++;
  }
  cout << ans;
}