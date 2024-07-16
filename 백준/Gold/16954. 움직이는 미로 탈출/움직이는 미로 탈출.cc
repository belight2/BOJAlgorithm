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
const int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
const int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
bool vis[10][10][10];
string board[10][10];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  for(int i = 0; i < 8; i++) cin >> board[0][i];

  for(int i = 1; i <= 8; i++){
    for(int j = 1; j < 8; j++) board[i][j] = board[i-1][j-1];
    board[i][0] = string(8, '.');
  }
  qti q;
  q.push({0, 7, 0});
  vis[0][7][0] = 1;
  while(!q.empty()){
    auto [ct, cx, cy] = q.front(); q.pop();
    if(board[ct][cx][cy] == '#') continue;
    for(int dir = 0; dir < 9; dir++){
      int nt = (ct < 8) ? ct + 1 : ct;
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
      if(board[ct][nx][ny] == '#' || vis[nt][nx][ny]) continue;
      vis[nt][nx][ny] = 1;
      q.push({nt, nx, ny});
    }
  }
  cout << vis[8][0][7];
}