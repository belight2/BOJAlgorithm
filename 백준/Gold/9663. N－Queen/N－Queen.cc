// Authored by : chjh2129
/*
  n * n 크기의 체스판에서 임의의 위치 (x, y)에 퀸을 놓았을 경우

  x 행과 y열에 다른 퀸을 놓지 못한다는 사실을 알 수 있습니다.

  따라서 used_row, used_col과 bool형 변수를 선언해 처리할 수 있습니다.

  퀸은 행과 열 뿐만 아니라 \ 방향 대각선과 / 방향 대각선으로 이동이 가능하고 이에 대한 처리가 필요합니다.

  각 위치값을 나열해서 분석해보면 (x, y) 위치 값을 가공해 대각선 정보들을 linear하게 관리할 수 있습니다.

  ex) 4 * 4 체스판

  (0, 0) (0, 1) (0, 2) (0, 3)
  (1, 0) (1, 1) (1, 2) (1, 3)
  (2, 0) (2, 1) (2, 2) (2, 3)
  (3, 0) (3, 1) (3, 2) (3, 3)

  같은 / 방향 대각선에 놓인 (x, y)는 x + y가 모두 같은 값을 가집니다.

  / 방향 대각선의 정보는 used_diag[x + y]로 알 수 있습니다.

  같은 \ 방향 대각선에 놓인 (x, y)는 y - x가 모두 같은 값을 가집니다.

  여기서 x > y인 위치는 음수값을 가지게되므로 (n-1)을 offset으로 이동시켜 0 이상의 값들을 가지게 합니다.

  \ 방향 대각선의 정보는 used_Xdiag[y - x + n - 1]로 알 수 있습니다.
*/
#include <bits/stdc++.h>

using namespace std;

int n, ans;

bool used_col[20]; // column
bool used_diag[40]; // /방향 대각선
bool used_Xdiag[40];// \방향 대각선
/*
  cx행에서 퀸을 놓을 수 있는 찾는다.
  
  한 행마다 하나의 퀸만 놓을 수 있으므로 used_row는 사실 필요없다.
*/
void solve(int cx){
  if(cx == n){
    ans++;
    return;
  }

  for(int cy = 0; cy < n; cy++){
    if(used_col[cy] || used_diag[cx + cy] || used_Xdiag[cy - cx + n - 1]) continue;
    used_col[cy] = used_diag[cx + cy] = used_Xdiag[cy - cx + n - 1] = 1;
    solve(cx+1);
    used_col[cy] = used_diag[cx + cy] = used_Xdiag[cy - cx + n - 1] = 0;
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;

  // solve
  solve(0);

  // output
  cout << ans;
}