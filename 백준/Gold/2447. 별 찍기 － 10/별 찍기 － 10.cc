// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
char board[6562][6562];

void fill_empty(int x, int y, int n){
  for(int i = x; i < x + n; i++){
    for(int j = y; j < y + n; j++){
      board[i][j] = ' ';
    }
  }
}

void solve(int x, int y, int n){
  if(n == 1) return;

  int nxt = n / 3;
  
  // ' '으로 채우기
  fill_empty(x + nxt, y + nxt, nxt);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(i == 1 && j == 1) continue;
      solve(x + i * nxt, y + j * nxt, nxt);      
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // init
  memset(board, '*', sizeof(board));
  
  // input
  cin >> n;
  
  // solve
  solve(0, 0, n);

  // output
  for(int i = 0; i < n; i++){
    board[i][n] = '\0'; // NULL 문자를 끝에 삽입
    cout << board[i] << '\n';
  }
}