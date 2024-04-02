#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
int board[1005][1005];
int dist[1005][1005];
int n, m;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
queue<pair<int,int>> q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  cin >> n >> m;
  fill(&dist[0][0], &dist[n][m+1], -1);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 2){ q.push({i, j}); dist[i][j] = 0;}
      if(board[i][j] == 0) dist[i][j] = 0;
    }
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 0 || (dist[nx][ny] != -1 && dist[nx][ny] <= dist[cur.X][cur.Y]+1)) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      q.push({nx,ny});
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << dist[i][j] << ' ';
    }
    cout << nl;
  }
}