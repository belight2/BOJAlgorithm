#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
int n, k, s, a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<vector<int>> d(n+1, vector<int>(n+1, INF));
  while(k--){
    cin >> a >> b;
    d[a][b] = 1;
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cin >> s;
  while(s--){
    cin >> a >> b;
    if(d[a][b] == INF && d[b][a] == INF) cout << "0\n";
    else if(d[a][b] == INF) cout << "1\n";
    else if(d[b][a] == INF) cout << "-1\n";
  }
}