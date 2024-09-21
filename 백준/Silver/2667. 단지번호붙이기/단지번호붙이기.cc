// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n;
char board[26][26];
bool vis[26][26];

int bfs(int sx, int sy){
  queue<pi> q;
  vis[sx][sy] = 1;
  q.push({sx, sy});

  int cnt = 1;
  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if((board[nx][ny] == '0') || vis[nx][ny]) continue;
      cnt++;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }

  return cnt;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }

  // solve
  vector<int> ans;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == '1' and !vis[i][j]){
        ans.push_back(bfs(i, j));
      }
    }
  }

  // output
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(auto x : ans) cout << x << '\n';
}