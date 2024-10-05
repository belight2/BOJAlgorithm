// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
char board[3074][6148];

void solve(int x, int y, int n){
  if(n == 3){
    board[x][y] = board[x+1][y-1] = board[x+1][y+1] = '*';
    for(int i = y-2; i < y+3; i++) board[x+2][i] = '*';
    return;
  }
  
  int nxt = n / 2;
  solve(x, y, nxt);
  solve(x + nxt, y - nxt, nxt);
  solve(x + nxt, y + nxt, nxt);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // init
  memset(board, ' ', sizeof(board));

  // input
  cin >> n;

  // solve
  solve(0, n-1, n);

  // output
  for(int i = 0; i < n; i++){
    board[i][2*n-1] = '\0'; // 문자열의 끝임을 알리는 '\0' 삽입
    cout << board[i] << '\n';
  }
}