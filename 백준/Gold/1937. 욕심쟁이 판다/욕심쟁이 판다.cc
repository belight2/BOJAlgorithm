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
int board[505][505];
int d[505][505];
int dfs(int cx, int cy){
  if(d[cx][cy] != 0) return d[cx][cy];
  bool flag{};
  for(int dir = 0; dir < 4; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[cx][cy] >= board[nx][ny]) continue;
    flag = 1;
    d[cx][cy] = max(d[cx][cy], dfs(nx, ny) + 1);
  }
  return (flag ? d[cx][cy] : 1);
}
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
    cin >> board[i][j];
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(d[i][j]) continue;
      d[i][j] = dfs(i, j);
    }
  }
  cout << *max_element(&d[0][0], &d[n][n+1]);
}