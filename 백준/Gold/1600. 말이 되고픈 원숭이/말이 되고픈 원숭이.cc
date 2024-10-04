// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ti = tuple<int,int,int>;

const int INF = 0x3f3f3f3f;
const int ddx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int ddy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m, k;
int board[203][203];
int dist[203][203][32];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> k >> m >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }

  // solve
  memset(dist, 0x3f, sizeof(dist));
  
  queue<ti> q;
  dist[0][0][0] = 0;
  q.push({0, 0, 0});

  while(q.size()){
    auto [cx, cy, move] = q.front(); q.pop();

    // 아직 k번 이하로 말처럼 이동한 상태라면 말처럼 이동
    if(move < k){
      for(int dir = 0; dir < 8; dir++){
        int nx = cx + ddx[dir];
        int ny = cy + ddy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(board[nx][ny] == 1 || dist[nx][ny][move+1] != INF) continue;
        dist[nx][ny][move+1] = dist[cx][cy][move] + 1;
        q.push({nx, ny, move+1});
      }
    }
    // 원숭이처럼 이동
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 1 || dist[nx][ny][move] != INF) continue;
      dist[nx][ny][move] = dist[cx][cy][move] + 1;
      q.push({nx, ny, move});
    }
  }

  // output
  int ans = *min_element(dist[n-1][m-1], dist[n-1][m-1]+k+1);
  cout << (ans == INF ? -1 : ans);
}