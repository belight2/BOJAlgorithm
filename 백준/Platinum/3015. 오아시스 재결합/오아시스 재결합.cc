#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
int n, x;
stack<pi> stk;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ll ans = 0;
  while(n--){
    cin >> x;
    int cnt = 1;
    while(!stk.empty() && stk.top().X <= x){
      ans += stk.top().Y;
      if(stk.top().X == x) cnt += stk.top().Y;
      stk.pop();
    }
    if(!stk.empty()) ans++;
    stk.push({x, cnt});
  }
  cout << ans;
}