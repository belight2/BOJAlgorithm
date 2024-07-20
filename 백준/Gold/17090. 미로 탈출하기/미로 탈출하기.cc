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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m;
int vis[505][505];
int d[505][505];
string board[505];
unordered_map<char, int> dir = {{'D', 0}, {'R', 1}, {'U', 2}, {'L', 3}};
int solve(int cx, int cy, int state){
  int idx = dir[board[cx][cy]];
  int nx = cx + dx[idx];
  int ny = cy + dy[idx];
  if(nx < 0 || nx >= n || ny < 0 || ny >= m) { return 1;}
  if(vis[cx][cy] == state) return 0;
  if(d[cx][cy]) return 1;
  vis[cx][cy] = state;
  d[cx][cy] = solve(nx, ny, state);
  return d[cx][cy];
}
int main() {
  fastio(nullptr, false);
  cin >> n >> m;
  int state{};
  for(int i = 0; i < n; i++) cin >> board[i];
  
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
      d[i][j] = solve(i, j, ++state); 
    
  int ans{};
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    ans += d[i][j];
  cout << ans;
}