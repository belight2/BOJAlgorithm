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
const int root = 1e6 + 5;
unordered_map<char, int> convert ={
  {'L', 3}, {'R', 1},
  {'U', 2}, {'D', 0}
};

int n, m;
vector<int> p(1'000'010, -1);
string board[1005];
bool vis[1005][1005];

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] > p[y]) swap(x, y);
  p[x] += p[y];
  p[y] = x;
}

void flood_fill(int sx, int sy){
  qpi q;
  vis[sx][sy] = 1;
  q.push({sx, sy});
  while(sz(q)){
    auto [cx, cy] = q.front(); q.pop();
    merge(root, cx * m + cy);
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[sx][sy] != board[nx][ny] || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> board[i];

  int cx, cy; string cmd;
  cin >> cx >> cy >> cmd;

  cx--; cy--;

  // solve
  for(char op : cmd){
    if(op == 'W'){ 
      flood_fill(cx, cy);
      continue;
    }
    int dir = convert[op];
    cx += dx[dir];
    cy += dy[dir];
  }

  // 마지막 위치 작업
  merge(root, cx * m + cy);
  for(int dir = 0; dir < 4; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    merge(root, nx * m + ny);
  }

  // output
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int cur = find(i * m + j);
      cout << (find(root) == cur ? '.' : '#');
    }
    cout << '\n';
  }
}