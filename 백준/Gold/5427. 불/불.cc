// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
string board[1001];
int f_dist[1001][1001]; // 불
int s_dist[1001][1001]; // 상근

void solve(){
  // init
  memset(f_dist, -1, sizeof(f_dist));
  memset(s_dist, -1, sizeof(s_dist));
  queue<pi> fq;
  queue<pi> sq;

  // input
  cin >> m >> n;
  for(int i = 0; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < m; j++){
      if(board[i][j] == '@'){
        sq.push({i, j});
        s_dist[i][j] = 0;
      }
      if(board[i][j] == '*'){
        fq.push({i, j});
        f_dist[i][j] = 0;
      }
    }
  }

  // solve
  while(!fq.empty()){
    auto [cx, cy] = fq.front(); fq.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '#' || f_dist[nx][ny] >= 0) continue;
      f_dist[nx][ny] = f_dist[cx][cy] + 1;
      fq.push({nx, ny});
    }
  }

  while(!sq.empty()){
    auto [cx, cy] = sq.front(); sq.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        cout << s_dist[cx][cy] + 1 << '\n';
        return;
      }
      if(board[nx][ny] == '#' || s_dist[nx][ny] >= 0) continue;
      if(f_dist[nx][ny] != -1 && f_dist[nx][ny] <= s_dist[cx][cy] + 1) continue;

      s_dist[nx][ny] = s_dist[cx][cy] + 1;
      sq.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE\n";
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}