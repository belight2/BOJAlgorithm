#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ull unsigned long long
using namespace std;
const char nl = '\n';
int n;
string f[10005];
void solve(){
  for(int i = 2; i <= n; i++){
    string a = f[i-1]; string b = f[i-2];
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size() != b.size()) a.size() < b.size() ? a.pb('0') : b.pb('0');
    string ret; int c{};
    for(int i = 0; i < a.size(); i++){
      int nxt = (a[i] - '0') + (b[i] - '0' )+ c;
      c = nxt / 10;
      ret.pb(nxt%10 +'0');
    }
    if(c) ret.pb(c+'0');
    reverse(ret.begin(), ret.end());
    f[i] = ret;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  f[0] = "0"; f[1] = "1";
  solve();
  cout << f[n];
}