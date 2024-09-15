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

int n;
int board[22][22], dist[22][22];
int sx, sy, s_size; // 상어
int f_count;
pi fish;

pi get_fish(int x, int y){
  if(fish.X == 21 || dist[x][y] < dist[fish.X][fish.Y]) return {x, y};
  if(dist[x][y] > dist[fish.X][fish.Y]) return fish;
  return min(fish, make_pair(x, y));
}

void bfs(){
  fish = {21, 21};
  for(int i = 0; i < n; i++) fill(dist[i], dist[i]+n, 0);

  qpi q;
  q.push({sx, sy});
  dist[sx][sy] = 1;
  while(sz(q)){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(board[nx][ny] > s_size) continue;
      if(dist[nx][ny] && dist[nx][ny] <= dist[cx][cy] + 1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
      // 먹을 수 있는 물고기 위치 구하기
      if(board[nx][ny] && board[nx][ny] < s_size) fish = get_fish(nx, ny);
    }
  }
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j] == 9){
        tie(sx, sy, s_size) = make_tuple(i, j, 2);
        board[i][j] = 0;
      }
      else if(board[i][j]) f_count++;
    }
  }


  // solve
  int ans{}, eat{};
  while(f_count--){
    bfs();
    auto [fx, fy] = fish;
    if(fx == 21) break;
    board[fx][fy] = 0;
    ans += dist[fx][fy] - 1;
    tie(sx, sy) = fish;
    if(++eat == s_size){
      s_size++;
      eat = 0;
    }
  }

  // output
  cout << ans;
}