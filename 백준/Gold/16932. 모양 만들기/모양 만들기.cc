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
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int n, m, ans;
int a[1005][1005];
int group = -1;
vector<vpi> dist(1005, vpi(1005));
void bfs(pi cur){
  group++;
  queue<pi> q;
  vpi path;
  q.push(cur);
  dist[cur.X][cur.Y] = {1, group};
  path.pb(cur);
  int k = 1;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(a[nx][ny] == 0 || dist[nx][ny].X )continue;
      dist[nx][ny] = { dist[cur.X][cur.Y].X + 1, group };
      path.pb({nx, ny});
      q.push({nx, ny});
      k++;
    }
  }
  for(auto &[x, y] : path) dist[x][y].X = k;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    cin >> a[i][j];
//#define DEBUG_
#ifndef DEBUG_
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++){
    if(a[i][j] && !dist[i][j].X) bfs({i, j});
    }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] == 0){
        int res = 0;
        unordered_map<int, bool> tmp;
        for(int dir = 0; dir < 4; dir++){
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(tmp.find(dist[nx][ny].Y) == tmp.end()){
            tmp[dist[nx][ny].Y] = 1;
            res += dist[nx][ny].X;
          }
        }
        ans = max(ans, res);
      }
    }
  }
  cout << ans+1;
#endif
#ifdef DEBUG_
#endif
}