// Authored by : chjh2129
#include <bits/stdc++.h>

/*
  각 섬마다 flood fill 기법을 통해 섬마다 고유한 번호를 가지게 한다.

  섬 부분을 모두 큐에 넣고 최단 거리 BFS를 진행한다.

  최단 거리 BFS 중

  탐색하려는 위치가 같은 섬이면 넘어간다.

  탐색하려는 위치가 바다라면 현재 위치의 섬 번호로 값을 대입하면서 BFS를 진행한다.

  ex)
  아래는 flood fill을 통해서 섬마다 고유 번호를 부여한 상태다.
  
  1 1 1 0 0
  1 0 0 0 0
  0 0 0 0 0
  0 0 0 0 2
  
  이 상태에서 BFS를 한 사이클 돌렸다고 한다면,

  1 1 1 1 0
  1 1 1 0 0
  1 0 0 0 2
  0 0 0 2 2

  와 같이 되었다고 할 수 있다.

  BFS를 계속 진행하게 된다면 board[nx][ny] != board[cx][cy](두 값 전부 0이 아님)인 곳을 찾을 수 있게 된다.

  두 섬에 다리를 잇게된다면 그 다리의 길이는 dist[cx][cy] + dist[nx][ny]가 된다.
*/
using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n;
int board[102][102];
int dist[102][102]; // 다리의 길이 정보
bool vis[102][102]; // 섬 번호 할당을 위한 방문 배열

// flood fill 기법을 통해서 섬 번호 할당
void assign_island_number(){
  queue<pi> q;
  int island_number = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!board[i][j] || vis[i][j]) continue;
      
      board[i][j] = ++island_number;
      vis[i][j] = 1;
      q.push({i, j});

      while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cx + dx[dir];
          int ny = cy + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(board[nx][ny] == 0 || vis[nx][ny]) continue;
          board[nx][ny] = island_number;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
  }  
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  // init
  memset(dist, -1, sizeof(dist));
  queue<pi> q;

  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j]){
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  // solve
  assign_island_number();
  
  int ans = 0x3f3f3f3f; // 약 10억 
  
  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(board[nx][ny] == board[cx][cy]) continue;
      // 다음 위치가 바다라면 아직 탐색을 하지 않은 곳이기 때문에 거리배열 비교 없이 바로 탐색 가능하다고 판단할 수 있음.
      // 바다
      if(board[nx][ny] == 0){
        board[nx][ny] = board[cx][cy];
        dist[nx][ny] = dist[cx][cy] + 1;
        q.push({nx, ny});
      }
      else ans = min(ans, dist[cx][cy] + dist[nx][ny]); // 다른 섬을 만남
    }
  }
  // output
  cout << ans;
}