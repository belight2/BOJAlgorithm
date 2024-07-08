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
int n, sx, sy, ex, ey;
int vis[55][55];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vs board(n);
  fill(&vis[0][0], &vis[n][n], -1);
  for(int i = 0; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < n; j++){
      if(board[i][j] == '#'){
        swap(sx, ex); swap(sy, ey);
        sx = i; sy = j;
      }
    }
  }
  qpi q;
  q.push({sx, sy});
  vis[sx][sy] = 0;
  while(!q.empty()){
    auto &[cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      while(0 <= nx && nx < n && 0 <= ny && ny < n && board[nx][ny] != '*'){
        if(vis[nx][ny] == -1){
          vis[nx][ny] = vis[cx][cy] + 1;
          if(board[nx][ny] == '!') q.push({nx, ny});
        }
        nx += dx[dir];
        ny += dy[dir];
      }
    }
  }
  cout << vis[ex][ey] - 1;
}