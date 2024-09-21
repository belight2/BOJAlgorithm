// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
int board[1000][1000];
bool vis[1000][1000];

void bfs(int sx, int sy){
  queue<pi> q;
  vis[sx][sy] = 1;
  q.push({sx, sy});

  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = (cx + dx[dir] + n) % n;
      int ny = (cy + dy[dir] + m) % m;
      if(vis[nx][ny] || board[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }

  // solve
  int ans{};

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(not board[i][j] and not vis[i][j]){
        ans++;
        bfs(i, j);
      }
    }
  }

  // output
  cout << ans;
}