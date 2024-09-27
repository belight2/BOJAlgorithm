// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ti = tuple<int,int,int>;

const int dx[6] = { 0, 0, 1, -1, 0, 0 };
const int dy[6] = { 1, -1, 0, 0, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, 1, -1 };

int n, m, h;
int board[103][103][103];
int dist[103][103][103];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // init
  queue<ti> q;

  // input
  cin >> m >> n >> h;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < m; k++){
        cin >> board[i][j][k];
        if(board[i][j][k] == 1) q.push({i, j, k});
        if(board[i][j][k] == 0) dist[i][j][k] = -1;
      }
    }
  }

  // solve
  while(!q.empty()){
    auto [cx, cy, cz] = q.front(); q.pop();
    
    for(int dir = 0; dir < 6; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      int nz = cz + dz[dir];
      if(nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
      if(dist[nx][ny][nz] >= 0) continue;
      dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
      q.push({nx,ny,nz});
    }
  }

  int ans{};
  for(int i = 0; i < h; i++){
    for(int j = 0; j < n; j++){
      if(*min_element(dist[i][j], dist[i][j]+m) == -1){
        cout << -1;
        return 0; // 프로그램 종료
      }
      ans = max(ans, *max_element(dist[i][j], dist[i][j] + m));
    }
  }
  
  // output
  cout << ans;
}