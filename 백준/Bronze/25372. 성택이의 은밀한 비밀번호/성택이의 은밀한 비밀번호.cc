#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve(){
  string s;
  cin >> s;
  string ans = "no";
  if( 6<= s.size() && s.size() <= 9) ans = "yes";
//#define DEBUG_
#ifndef DEBUG_
  cout << ans << nl;
#endif
#ifdef DEBUG_
#endif
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t{};
  cin >> t;
  while(t--) solve();
}