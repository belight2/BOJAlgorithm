#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, m, ans;
int board[1000][1000];
bool vis[1000][1000];
void bfs(int sx, int sy){
  qpi q;
  vis[sx][sy] = 1;
  q.push({sx, sy});
  while(!q.empty()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = (cx + dx[dir]) % n;
      int ny = (cy + dy[dir]) % m;
      nx = (nx < 0) ? n-1 : nx;
      ny = (ny < 0) ? m-1 : ny;
      if(vis[nx][ny] || board[nx][ny] ) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}
int main() {
  fastio(nullptr, false);
  cin >> n >> m;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    cin >> board[i][j];
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    if(!board[i][j] && !vis[i][j]){
      ans++;
      bfs(i, j);
    }
  cout << ans;
}