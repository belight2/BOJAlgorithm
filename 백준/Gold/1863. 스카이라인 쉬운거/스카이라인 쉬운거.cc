// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int n;
int y[1'000'005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  int tmp; // x값은 버리고 높이 y값만 입력받는다.
  for(int i = 0; i < n; i++) cin >> tmp >> y[i];

  // solve;
  int ans{};
  stack<int> stk;
  for(int i = 0; i < n; i++){
    while(!stk.empty() && stk.top() > y[i]) stk.pop();
    if(y[i] && (stk.empty() || stk.top() < y[i])){
      stk.push(y[i]);
      ans++;
    }
  }

  // output
  cout << ans;
}