// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;
int d[1001][1001];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> a >> b;

  n = a.size();
  m = b.size();

  // solve
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
      else if(d[i - 1][j] > d[i][j - 1]) d[i][j] = d[i - 1][j];
      else d[i][j] = d[i][j - 1];
    }
  }

  // output
  cout << d[n][m];
}