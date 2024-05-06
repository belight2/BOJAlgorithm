#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n; cin >> n;
  vector<vector<int>> dp(n+1, vector<int>(45001, -1));
  vector<int> a(n);
  vector<int> res;
  int sum = 0, half = n / 2;
  for(int &x : a){
    cin >> x;
    sum += x;
  }
  dp[0][0] = 0;
  for(int i = 0; i < n; i++){
    for(int j = sum - a[i]; j >= 0; j--){
      if(dp[i][j] == -1) continue;
      dp[i+1][j+a[i]] = dp[i][j] + 1;
      dp[i+1][j] = dp[i][j];
      if(dp[i+1][j+a[i]] == half) res.push_back(j+a[i]);
    }
  }
  int ans, mindif = sum;
  for(int kg : res){
    int dif = abs(sum - kg - kg);
    if(dif < mindif){
      mindif = dif;
      ans = kg;
    }
  }
  cout << min(sum - ans, ans) << ' ' << max(sum-ans, ans) << ' ';
  cout << "\n\n";
}
int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  //cin >> t;
  while(t--) solve();
}