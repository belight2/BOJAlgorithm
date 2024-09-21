// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int mxlimit, limit;
int n;
int board[105][105];
bool vis[105][105];

void bfs(int sx, int sy, int limit){
  queue<pi> q;
  vis[sx][sy] = 1;
  q.push({sx, sy});

  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(vis[nx][ny] || board[nx][ny] <= limit) continue;
      vis[nx][ny] = 1;
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
      cin >> board[i][j];
      mxlimit = max(mxlimit, board[i][j]);
    }
  }

  // solve
  int ans{};

  for(int limit = 0; limit < mxlimit; limit++){
    memset(vis, 0, sizeof(vis));

    int cnt = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(board[i][j] > limit and !vis[i][j]){
          cnt++;          
          bfs(i, j, limit);
        }
      }
    }

    ans = max(ans, cnt);
  }

  // output
  cout << ans;
}