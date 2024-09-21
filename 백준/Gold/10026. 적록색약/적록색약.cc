// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n;
char board[2][105][105]; // 0 : 적록색약 X, 1 : 적록색약 O
bool vis[2][105][105];

void bfs(int k, int sx, int sy){
  queue<pi> q;
  q.push({sx, sy});
  vis[k][sx][sy] = 1;
  
  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(vis[k][nx][ny] || board[k][nx][ny] != board[k][sx][sy]) continue;
      vis[k][nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[0][i][j];
      // 적록색약은 R과 G를 구분 못하니 R을 모두 G로 바꿈
      board[1][i][j] = (board[0][i][j] == 'R' ? 'G' : board[0][i][j]);
    }
  }

  // solve
  for(int k = 0; k < 2; k++){
    int ans{};
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(vis[k][i][j]) continue;
        ans++;
        bfs(k, i, j);
      }
    }

    // output
    cout << ans << ' ';
  }
}