#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
const int INF = 1e9+100;
int n, m;
int a[1005];
int dp[1005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  fill(dp, dp+n+1, INF);
  dp[0] = 0;
  for(int i = 0; i < n; i++){
    int s = -1;
    for(int j = i; j >= 0; j--){
      s += a[j] + 1;
      if(s > m) break;
      dp[i+1] = min(dp[i+1], dp[j] + (m-s)*(m-s));
    }
  }
  int ans = INF, s = -1;
  for(int i = n-1; i >= 0; i--){
    s += a[i] + 1;
    if(s > m) break;
    ans = min(ans, dp[i]);
  }
  cout << ans;
}