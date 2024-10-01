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

// R, D, L, U
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

unordered_map<char, int> dir;

int n, m;
string board[1005];
int vis[1005][1005];

int dfs(int cx, int cy, int count){
  int nxt = dir[board[cx][cy]];
  int nx = cx + dx[nxt];
  int ny = cy + dy[nxt];
  vis[cx][cy] = count;
  return (vis[cx][cy] = (vis[nx][ny] ? vis[nx][ny] : dfs(nx, ny, count)));
}

int main() {
  fastio(nullptr, false);

  // init
  dir['R'] = 0; dir['D'] = 1; dir['L'] = 2; dir['U'] = 3;
  
  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> board[i];
  }

  // solve
  int count{}, ans{};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j] == 0){
        vis[i][j] = ++count;
        ans = max(ans, count = dfs(i, j, count));
        count = ans;
      }
    }
  }

  // output
  cout << ans;
}