#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
int a, b, n, m, x, y;
char d;
int board[105][105];
int robot[105][3]; // 각 로봇 위치와 방향
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int flag;
unordered_map<char, int> mp;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mp['E'] = 0;
  mp['S'] = 1;
  mp['W'] = 2;
  mp['N'] = 3;
  cin >> b >> a >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> y >> x >> d;
    robot[i][0] = x;
    robot[i][1] = y;
    robot[i][2] = mp[d];
    board[x][y] = i;
  }
  int no, rep;
  char op;
  int retX, retY;
  while(m--){
    cin >> no >> op >> rep;
    if(op == 'L') robot[no][2] = (robot[no][2]+ 3*rep) % 4;
    else if(op == 'R') robot[no][2] = (robot[no][2]+ rep) % 4;
    else{
      retX = no;
      int cx = robot[no][0];
      int cy = robot[no][1];
      int dir = robot[no][2];
      for(int _ = 0; _ < rep; _++){
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(nx < 1 || nx > a || ny < 1 || ny > b){flag = 1; break;}
        if(board[nx][ny] != 0){retY = board[nx][ny]; flag = 2; break;}
        board[nx][ny] = no;
        board[cx][cy] = 0;
        cx = nx; cy = ny;
      }
      if(flag) break;
      robot[no][0] = cx;
      robot[no][1] = cy;
    }
   
  }
  if(flag == 0) cout << "OK";
  else if(flag == 1) cout << "Robot " << retX << " crashes into the wall";
  else cout << "Robot " << retX << " crashes into robot " << retY;
}