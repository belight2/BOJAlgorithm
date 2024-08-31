#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n;
int d[2][1'000'005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  d[0][1] = 2; // 두 명 중 한명만 선택한 경우의 수
  d[1][1] = 1; // 두 명 모두 선택한 경우의 수
  for(int i = 2; i <= n; i++){
    for(int j = 0; j < 2; j++){
      d[0][i] = (d[0][i] + (d[j][i-1] * 2) % MOD ) % MOD;
    }
    d[1][i] = d[0][i-1];
  }
  cout << (d[0][n] + d[1][n]) % MOD;
}