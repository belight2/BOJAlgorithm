// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
int paper[2200][2200];
int ans[3];

/*
  종이의 좌측 상단 점 : (x, y)
  종이의 크기 : n
  
  이 때 종이 내부가 모두 같은 값으로 채워져 있는지 검사하는 함수
*/
bool chk(int x, int y, int n){
  for(int i = x; i < x + n ; i++)
  for(int j = y; j < y + n; j++)
    if(paper[x][y] != paper[i][j])
      return 0;
  return 1;
}

/*
  종이의 좌측 상단 점:  (x, y)
  종이의 크기 : n
*/
void solve(int x, int y, int n){
  // base condition
  if(chk(x, y, n)){
    ans[paper[x][y]]++;
    return;
  }

  int nxt = n / 3;

  for(int i = 0; i < 3; i++)
  for(int j = 0; j < 3; j++)
    solve(x + i * nxt, y + j * nxt, nxt);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // init
  int n;

  // input
  cin >> n;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++){
    cin >> paper[i][j];
    paper[i][j]++;
  }

  // solve  
  solve(0, 0, n);

  // output
  for(int i = 0; i < 3; i++)
    cout << ans[i] << '\n';
}