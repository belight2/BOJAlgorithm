// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int t, ans;
string s;

// solve
bool solve(){
  stack<char> stk;
  for(auto c : s){
    if(!stk.empty() && stk.top() == c) stk.pop();
    else stk.push(c);
  }
  return stk.empty();
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input & solve
  cin >> t;
  while(t--){
    cin >> s;
    ans += solve();
  }

  // output
  cout << ans;
}