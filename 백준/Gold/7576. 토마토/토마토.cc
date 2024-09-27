// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
int board[1005][1005];
int dist[1005][1005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // init
  queue<pi> q;

  // input
  cin >> m >> n; // 열의 크기부터 주어짐
  /*
    익은 토마토가 있는 곳은 큐에 삽입을 해준다.
    익지않은 토마토가 있는 곳은 거리배열을 -1로 초기화한다.
    토마토가 위치하지 않은 곳은 0으로 둔다.
  */
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        q.push({i, j});
        dist[i][j] = 0;
      }
      if(!board[i][j]) dist[i][j] = -1;
    }
  }
  

  // solve
  while(!q.empty()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny] >= 0) continue; // 익지 않은 토마토에 대해서만 정보를 갱신해준다.
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
    }
  }

  int ans{};
  for(int i = 0; i < n; i++){
    if(*min_element(dist[i], dist[i]+m) == -1){
      cout << -1;
      return 0; // 프로그램 종료
    }
    ans = max(ans, *max_element(dist[i], dist[i]+m));
  }

  // output
  cout << ans;
}