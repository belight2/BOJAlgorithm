// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
string board[1001];
int f_dist[1001][1001]; // 불 도달 시간
int j_dist[1001][1001]; // 지훈 도달 시간

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // init
  memset(f_dist, -1, sizeof(f_dist));
  memset(j_dist, -1, sizeof(j_dist));
  queue<pi> fq; // 불
  queue<pi> jq; // 지훈

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < m; j++){
      if(board[i][j] == 'F'){
        fq.push({i, j});
        f_dist[i][j] = 0;
      }
      if(board[i][j] == 'J'){
        jq.push({i, j});
        j_dist[i][j] = 0;
      }
    }
  }

  // solve
  // 불에 대해서 먼저 bfs를 진행
  while(!fq.empty()){
    auto [cx, cy] = fq.front(); fq.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(f_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      f_dist[nx][ny] = f_dist[cx][cy] + 1;
      fq.push({nx, ny});
    }
  }

  // 지훈이에 대해서 bfs를 진행
  while(!jq.empty()){
    auto [cx, cy] = jq.front(); jq.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        // 배열의 범위를 벗어났다 = 탈출
        // 거리순으로 큐에 삽입되므로 최초의 값만 출력하면 됨
        cout << j_dist[cx][cy] + 1;
        return 0;
      }
      if(j_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
      if(f_dist[nx][ny] != -1 && f_dist[nx][ny] <= j_dist[cx][cy] + 1) continue; // 지훈이보다 불이 먼저 전파되어있음
      j_dist[nx][ny] = j_dist[cx][cy] + 1;
      jq.push({nx, ny});
    }
  }

  // 탈출 실패
  cout << "IMPOSSIBLE";
}