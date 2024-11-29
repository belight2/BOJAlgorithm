// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
string a, b;
int d[1005][1005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> a >> b;
  
  // init
  n = a.size();
  m = b.size();
  for(int i = 1; i <= max(n, m); i++) d[i][0] =  d[0][i] = i;

  // solve
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1]){
        d[i][j] = d[i-1][j-1];
        continue;
      }

      d[i][j] = 1 + min({d[i-1][j], d[i-1][j-1], d[i][j-1]});
    }
  }

  // output
  cout << d[n][m];
}