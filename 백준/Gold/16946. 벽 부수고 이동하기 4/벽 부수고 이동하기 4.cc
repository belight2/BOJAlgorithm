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

vi p(1000005, -1);

int find(int x) { return (p[x] < 0 ? x : p[x] = find(p[x])); }

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] > p[y]) swap(x, y);
  p[x] += p[y];
  p[y] = x;
}

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m;
string board[1005];
bool vis[1005][1005];

bool OOB(int x, int y){
  return x < 0 || x >= n || y < 0 || y >= m;
}

void bfs(int sx, int sy){
  int root = sx * m + sy;
  qpi q;
  vis[sx][sy] = 1;
  q.push({sx, sy});
  while(q.size()){
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(OOB(nx, ny) || board[nx][ny] == '1' || vis[nx][ny]) continue;    
      vis[nx][ny] = 1;
      q.push({nx, ny});

      // 머지  
      merge(root, nx * m + ny);
    }
  }
}

int chk(int cx, int cy){
  set<int> group;
  int ret = 1;
  for(int dir = 0; dir < 4; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(OOB(nx, ny) || board[nx][ny] == '1') continue;
    int nxt = find(nx * m + ny);
    group.insert(nxt);
  }
  for(auto cur : group) ret += abs(p[cur]);
  return ret % 10;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n ; i++) cin >> board[i];

  // solve
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(board[i][j] == '1' || vis[i][j]) continue;
      bfs(i, j);
    }
  }

  // output
  for(int cx = 0; cx < n; cx++){
    for(int cy = 0; cy < m; cy++){
      cout << (board[cx][cy] == '0' ? 0 : chk(cx, cy));
    }
    cout << nl;
  }
}