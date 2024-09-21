// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>; // <utility>
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
char board[606][606];
bool vis[606][606]; // 방문 배열
pi st; // 시작 위치

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 'I') st = {i, j};
    }
  }

  // init
  int ans{};
  queue<pi> q;
  q.push(st);
  vis[st.X][st.Y] = 1;

  // solve
  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 'X' || vis[nx][ny]) continue;
      if(board[nx][ny] == 'P') ans++;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }

  // output
  ans ? (cout << ans) : (cout << "TT");
}