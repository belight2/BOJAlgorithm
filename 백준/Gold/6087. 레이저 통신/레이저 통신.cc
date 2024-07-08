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
int n, m, sx, sy, ex, ey;
char board[105][105];
int vis[105][105];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m >> n;
  for(int i = 0; i < n; i++){
    string line;
    cin >> line;
    for(int j = 0; j < m; j++){
      board[i][j] = line[j];
      if(line[j] == 'C'){
        swap(sx, ex); swap(sy, ey);
        sx = i; sy = j;
      }
    }
  }
  queue<pi> q;
  vis[sx][sy] = 1;
  q.push({sx, sy});
  while(!q.empty()){
    auto &[cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      while(0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] != '*'){
        if(vis[nx][ny] == 0){
          vis[nx][ny] = vis[cx][cy] + 1;
          q.push({nx, ny});
        }
        nx += dx[dir];
        ny += dy[dir];
      }
    }
  }
  cout << max(0, vis[ex][ey]-2);
}