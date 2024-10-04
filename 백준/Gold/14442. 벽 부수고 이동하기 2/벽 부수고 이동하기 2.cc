#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

queue<tuple<int,int,int>> q;
int n, m, k;
char board[1005][1005];
int vis[11][1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(){
  vis[0][0][0] = 1;
  q.push({0,0,0});
  while(!q.empty()){
    int state, curX, curY;
    tie(state, curX, curY) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = curX+dx[dir];
      int ny = curY+dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '1' && state + 1 <= k && vis[state+1][nx][ny] > vis[state][curX][curY] + 1 ){
        vis[state+1][nx][ny] = vis[state][curX][curY] + 1;
        q.push({state+1, nx, ny});
      }
      if(board[nx][ny] == '0' && vis[state][nx][ny] > vis[state][curX][curY] + 1 ){
        vis[state][nx][ny] = vis[state][curX][curY] + 1;    
        q.push({state, nx, ny});
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i <= 10; i++)
    for(int j = 0; j <= 1000; j++)
      fill(vis[i][j], vis[i][j]+1005, INF);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < m; j++){
      board[i][j] = s[j];
    }
  }
  bfs();
  int res = INF;
  for(int i = 0; i <= k; i++) res = min(res, vis[i][n-1][m-1]);
  if(res == INF) cout << -1;
  else cout << res;
}