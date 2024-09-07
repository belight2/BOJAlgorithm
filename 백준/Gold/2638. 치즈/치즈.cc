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
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
int board[105][105];
vector<pi> edge;

/*
  외부 공기를 모두 -1로 값을 바꾼다.
*/
void fill_air(int x, int y){
  qpi q;
  board[x][y] = -1;
  q.push({x, y});
  while(sz(q)){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] != 0) continue;
      board[nx][ny] = -1;
      q.push({nx, ny});
    }
  }
}

bool chk(int x, int y){
  int cnt{};
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    cnt += (board[nx][ny] == -1);
  }
  return cnt >= 2;
}

void edge_detect(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == 1 && chk(i, j)) edge.pb({i, j});
    }
  }
}


int main() {
  fastio(nullptr, false);

  // input
  int cheese{};
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j]) cheese++;
    }
  }

  // init
  fill_air(0, 0);

  // solve
  int ans{};
  // cheese의 개수가 0이 아니라면
  while(cheese){
    // 가장 자리에 놓인 치즈를 탐지한다.
    edge_detect();

    cheese -= sz(edge);

    while(sz(edge)){
      auto cur = edge.back(); edge.pop_back();
      board[cur.X][cur.Y] = -1;
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(board[nx][ny] == 0) fill_air(nx, ny);
      }
    }

    ans++;
  }

  cout << ans;
}