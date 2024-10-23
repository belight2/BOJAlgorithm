// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ti = tuple<int, int, int>;
using pi = pair<int, int>;
#define X first
#define Y second

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
int board[15][15];
int dist[15][15];
bool vis[15][15];

int mx;
vector<ti> edge;
vector<int> p(105, -1);

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  if(p[x] == p[y]) p[x]--;
  if(p[x] > p[y]) swap(x, y);
  p[y] = x;
  return 1;
}

int assign_island_number(){
  queue<pi> q;
  int island_number{};

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!board[i][j] || vis[i][j]) continue;
      board[i][j] = ++island_number;
      q.push({i, j});
      vis[i][j] = 1;
      while(q.size()){
        auto [cx, cy] = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cx + dx[dir];
          int ny = cy + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(!board[nx][ny] || vis[nx][ny]) continue;
          board[nx][ny] = island_number;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
  }
  return island_number;
}

void chk_and_addEdge(int cx, int cy, int dir){
  int cur_island = board[cx][cy];
  int dist = 0;
  cx += dx[dir];
  cy += dy[dir];
  while(0 <= cx && cx < n && 0 <= cy && cy < m){
    if(board[cx][cy] == cur_island) break;
    if(board[cx][cy] && board[cx][cy] != cur_island){
      if(dist > 1) edge.push_back({dist, cur_island, board[cx][cy]});
      return;
    }
    cx += dx[dir];
    cy += dy[dir];
    dist++;
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }

  mx = assign_island_number(); // 정점의 개수

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(!board[i][j]) continue;
      for(int dir = 0; dir < 4; dir++){
        chk_and_addEdge(i, j, dir);
      }
    }
  }

  int cnt{}, ans{};
  sort(edge.begin(), edge.end());
  for(auto &[cost, u, v] : edge){
    if(cnt == mx - 1) break;
    if(!merge(u, v)) continue;
    ans += cost;
    cnt++;
  }

  cout << (cnt == mx - 1 ? ans : -1);
}