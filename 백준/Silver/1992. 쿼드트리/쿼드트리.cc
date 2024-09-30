// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
string image[66];

bool chk(int x, int y, int n){
  for(int i = x; i < x + n; i++){
    for(int j = y; j < y + n; j++){
      if(image[x][y] != image[i][j])
        return 0;
    }
  }
  return 1;
}

void solve(int x, int y, int n){
  if(chk(x, y, n)){
    cout << image[x][y];
    return;
  }
  cout << '(';
  int nxt = n >> 1;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      solve(x + i * nxt, y + j * nxt, nxt);
    }
  }
  cout << ')';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> image[i];
  
  // solve
  solve(0, 0, n);
}