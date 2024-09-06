// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int t;
string s;

// 짝이 맞으면 true, 틀리면 false를 반환
bool solve(){
  stack<char> stk;
  for(auto c : s){
    if(c == '(') stk.push(c);
    else if(stk.empty() || stk.top() != '(') return 0;
    else stk.pop();
  }
  return stk.empty();
} 

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> t;
  while(t--){
    cin >> s;
    // solve & output
    cout << (solve() ? "YES\n" : "NO\n");
  }
}