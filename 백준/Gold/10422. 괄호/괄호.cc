#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const char nl = '\n';
const ll MOD = 1e9 + 7;
ll d[2505];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  d[0] = 1;
  for(int i = 1; i <= 2500; i++){
    for(int j = 0; j < i; j++){
      d[i] = (d[i] + d[j] * d[i-j-1]) % MOD;
    }
  }
  int t;
  cin >> t;
  while(t--){
    int x, ans;
    cin >> x;
    ans = x&1 ? 0 : d[x/2];
    cout << ans << nl;
  }
}