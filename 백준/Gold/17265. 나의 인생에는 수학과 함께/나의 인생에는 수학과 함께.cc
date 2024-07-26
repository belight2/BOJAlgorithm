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
const int INF = 0x3f3f3f3f;
const int dx[2] = { 1, 0 };
const int dy[2] = { 0, 1 }; 
int n, mx = -INF, mn = INF;
char board[6][6];
void dfs(int cx, int cy, int tot){
  if(cx == n-1 && cy == n-1){
    mx = max(mx, tot);
    mn = min(mn, tot);
    return;
  }
  for(int dir = 0; dir < 2; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx >= n || ny >= n) continue;
    if(board[cx][cy] == '*') dfs(nx, ny, tot * (board[nx][ny]-'0'));
    else if(board[cx][cy] == '+') dfs(nx, ny, tot + (board[nx][ny]-'0'));
    else if(board[cx][cy] == '-') dfs(nx, ny, tot - (board[nx][ny]-'0'));
    else dfs(nx, ny, tot);
  }
}
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
    cin >> board[i][j];
  dfs(0, 0, board[0][0]-'0');
  cout << mx << ' ' << mn;
}