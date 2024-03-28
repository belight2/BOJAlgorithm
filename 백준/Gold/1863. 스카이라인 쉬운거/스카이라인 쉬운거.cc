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
int n;
int y[1000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int gbg;
  for(int i = 0; i < n; i++) cin >> gbg >> y[i];
  y[n] = 0;
  stack<int> stk;
  ll ans = 0;
  for(int i = 0; i <= n; i++){
    int cur = y[i];
    if(stk.empty() || stk.top() < cur) stk.push(cur);
    while(!stk.empty() && stk.top() > cur){
      stk.pop(); ans++;
    }
    if(cur == 0 || (!stk.empty() && stk.top() == cur)) continue;
    stk.push(cur);
  }
  cout << ans;
}