// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int n, h;
stack<int> stk;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> h;

  // init
  stk.push(1'000'000'005);
  stk.push(h);

  // solve
  long long ans{};
  for(int i = 1; i < n; i++){
    cin >> h;
    while(stk.top() <= h) stk.pop();
    ans += stk.size() - 1;
    stk.push(h);
  }

  // output
  cout << ans;
}