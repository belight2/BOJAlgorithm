#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
int N;
bool adj_matrix[105][105];
int vis[105][105];
queue<int> q;
void bfs(int start){
  q.push(start);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int nxt = 1; nxt <= N; nxt++){
      if( !adj_matrix[cur][nxt] || vis[start][nxt]) continue;
      vis[start][nxt] = 1;
      q.push(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> adj_matrix[i][j];
    }
  }
  for(int i = 1; i <= N; i++) bfs(i);
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cout << vis[i][j] << ' ';
    }
    cout << nl;
  }

}