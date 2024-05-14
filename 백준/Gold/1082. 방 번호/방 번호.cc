#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define null ""
const char nl = '\n';
int n, m;
vi a;
bool mxnum(const string &a, const string &b){
  if(a.size() == b.size()){
    for(int i = 0; i < a.size(); i++){
      if(a[i] == b[i]) continue;
      return ((a[i] < b[i]) ?  0 : 1);
    }
  }
  return ((a.size() < b.size()) ? 0 : 1 );
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  a.resize(n);
  for(int &x : a) cin >> x;
  cin >> m;
  vs dp(m+1, null);
  for(int i = 0; i < n; i++){
    if(m-a[i] < 0) continue;
    if(dp[m-a[i]] == null) dp[m-a[i]].pb(i + '0');
    else dp[m-a[i]][0] = i+'0';
  }
  string ans = "0";
  for(int i = m; i >= 0; i--){
    if(dp[i] == null) continue;
    for(int j = 0; j < n; j++){
      if(i - a[j] < 0) continue;
      if(dp[i] == "0") continue;
      string tmp = dp[i];
      tmp.pb(j+'0');
      dp[i-a[j]] = mxnum(dp[i-a[j]], tmp) ? dp[i-a[j]] : tmp;
    }
  }
  for(int i = 0; i <= m; i++){
    if(dp[i] == null) continue;
    ans = mxnum(ans, dp[i]) ? ans : dp[i];
    // cout << i << " : " << dp[i] << nl;
  }
  cout << ans;
}