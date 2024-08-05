#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n+1, vector<int>(n+1));
  vector<vector<int>> s(n+1, vector<int>(n+1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    }
  }
  while(m--){
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    cout << s[ex][ey] - s[ex][sy-1] - s[sx-1][ey] + s[sx-1][sy-1] << "\n";
  }
}