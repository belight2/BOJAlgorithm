// Authored by : chjh2129
// http://boj.kr/f6f804dcc7a9441a81e300ce998c964d
#include <bits/stdc++.h>

using namespace std;

int n, m, a;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;

  vector<vector<int>> s(n+1, vector<int>(n+1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a;
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a;
    }
  }

  while(m--){
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    cout << s[ex][ey] - s[ex][sy-1] - s[sx-1][ey] + s[sx-1][sy-1] << "\n";
  }
}