#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
// 남, 동, 북, 서
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
vs board(55);
bool vis[55][55][2505];
int n, sx, sy, ex, ey;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < n; j++){
      if(board[i][j] == '#'){
        swap(sx, ex); swap(sy, ey);
        sx = i; sy = j;
      }
    }
  }
  int ans = 1e5;
  queue<ti> q;
  for(int dir = 0; dir < 4; dir++) q.push({sx, sy, 0, dir});
  vis[sx][sy][0] = 1;
  while(!q.empty()){
    auto &[cx, cy, m, dir] = q.front(); q.pop();
    if(cx == ex && cy == ey) ans = min(ans, m);
    if(board[cx][cy] == '*') continue;
    if(board[cx][cy] == '!'){
      int ndir = (dir+1)%4, pdir = (dir+3)%4;
      int nx = cx + dx[ndir]; int ny = cy + dy[ndir];
      int px = cx + dx[pdir]; int py = cy + dy[pdir];
      if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny][m+1]){
        q.push({nx, ny, m+1, ndir});
        vis[nx][ny][m+1] = 1;
      }
      if(px >= 0 && px < n && py >= 0 && py < n && !vis[px][py][m+1]){
        q.push({px, py, m+1, pdir});
        vis[px][py][m+1] = 1;
      }
    }
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny][m]) continue;
    q.push({nx, ny, m, dir});
  }
  cout << ans;
}