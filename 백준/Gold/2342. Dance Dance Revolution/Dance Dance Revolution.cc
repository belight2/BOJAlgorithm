#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
int e[5][5] ={
  {0, 2, 2, 2, 2},
  {0, 1, 3, 4, 3},
  {0, 3, 1, 3, 4},
  {0, 4, 3, 1, 3},
  {0, 3, 4, 3, 1}
};
int d[2][5][5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> a;
  int x;
  while(cin >> x, x) a.pb(x);
  fill(&d[0][0][0], &d[1][4][5], INF);
  d[0][0][0] = 0;
  for(int x : a){
    fill(&d[1][0][0], &d[1][4][5], INF);
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        d[1][x][i] = min(d[1][x][i], d[0][j][i] + e[j][x]);
        d[1][i][x] = min(d[1][i][x], d[0][i][j] + e[j][x]);
      }
    }
    memcpy(d[0], d[1], sizeof(d[1]));
  }
  int ans = *min_element(&d[0][0][0], &d[1][0][0]);
  cout << ans;
}