#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m;
int board[505][505];
int d[505][505];
int dfs(int cx, int cy){
  if(cx == n-1 && cy == m-1) return 1;
  if(d[cx][cy] != -1) return d[cx][cy];
  d[cx][cy] = 0;
  for(int dir = 0; dir < 4; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] < board[cx][cy])
      d[cx][cy] += dfs(nx, ny);
  }
  return d[cx][cy];
}
int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < m; j++)
    cin >> board[i][j];
  fill(&d[0][0], &d[n][m], -1);
  cout << dfs(0, 0); 
}