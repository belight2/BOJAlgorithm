#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
int n, m;
vector<bool> date(105, 1);
int d[105][55];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  fill(&d[0][0], &d[n][55], INF);
  while(m--){
    int x;
    cin >> x;
    date[x] = 0;
  }
  d[0][0] = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 50; j++){
      if(!date[i]){
        d[i][j] = min(d[i][j], d[i-1][j]);
        continue;
      }
      d[i][j] = d[i-1][j] + 10;
      if(j > 0) d[i][j] = min(d[i][j], d[max(i-3, 0)][j-1] + 25 );
      if(j > 1) d[i][j] = min(d[i][j], d[max(i-5, 0)][j-2] + 37 );
      if(j+3 < 50)  d[i][j] = min(d[i][j], d[i-1][j+3]);
    }
  }
  int ans = *min_element(d[n], d[n] + 55);
  cout << ans * 1000;
}