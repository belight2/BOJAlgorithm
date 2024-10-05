#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
using pi = pair<int,int>;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pi> q;
int vis[126][126];
int idx = 1;
void solve(){
  fill(&vis[0][0], &vis[n][n], INF);
  vector<vector<int>> a(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
  vis[0][0] = a[0][0];
  q.push({0, 0});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(vis[nx][ny] <= vis[cur.X][cur.Y] + a[nx][ny]) continue;
      q.push({nx,ny});
      vis[nx][ny] = vis[cur.X][cur.Y] + a[nx][ny];
    }
  }
  cout << "Problem " << idx++ << ": " << vis[n-1][n-1] << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin >> n, n) solve();
}