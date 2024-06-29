#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int n, m;
int board[55][55];
int vis[55][55];
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
vector<int> ans;
int cnt = 0;
void bfs(int sx, int sy){
  queue<pi> q;
  q.push({sx, sy});
  vis[sx][sy] = cnt;
  int area = 1;
  while(!q.empty()){
    auto &[cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      // 벽이 있는 상태
      if(board[cx][cy] & (1 << dir)) continue;
      if(vis[nx][ny]) continue;
      area++;
      vis[nx][ny] = cnt;
      q.push({nx, ny});
    }
  }
  ans.pb(area);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m >> n;
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    cin >> board[i][j];
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j]) continue;
      cnt++;
      bfs(i, j);
    }
  }
  int max_area{};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int cur_idx = vis[i][j];
      for(int dir = 0; dir < 4; dir++){
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        int nxt_idx = vis[nx][ny];
        if(cur_idx == nxt_idx) continue;
        max_area = max(max_area, ans[cur_idx-1] + ans[nxt_idx-1]);
      }
    }
  }
  cout << cnt << nl << *max_element(ans.begin(), ans.end()) << nl << max_area;
}