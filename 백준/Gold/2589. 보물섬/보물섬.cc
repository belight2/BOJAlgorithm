#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int n, m;
char board[55][55];
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
queue<pi> q;
int ans = 0;
void bfs(int sx, int sy){
  vector<vi> dist(n, vi(m, -1));
  dist[sx][sy] = 0;
  int res = 0;
  q.push({sx, sy});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
      if(board[nx][ny] == 'W' || ( dist[nx][ny] != -1 && dist[cur.X][cur.Y] + 1 >= dist[nx][ny])) continue;
      dist[nx][ny] = dist[cur.X][cur.Y] + 1 ;
      q.push({nx, ny});
      res = max(res, dist[nx][ny]);
    }
  }
  ans = max(ans, res);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  string line;
  vpi pos;
  for(int i = 0; i < n; i++){
    cin >> line;
    for(int j = 0; j < m; j++){
      board[i][j] = line[j];  
      if(line[j] == 'L') pos.pb({i, j});
    }
  }
//#define DEBUG_
#ifndef DEBUG_
  for(pi cur : pos) bfs(cur.X, cur.Y);
  cout << ans;
#endif
#ifdef DEBUG_
#endif
}