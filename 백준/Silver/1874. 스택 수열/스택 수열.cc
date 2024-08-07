#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);  

  cin >> n;

  vector<int> a(n);
  for(auto &x : a) cin >> x;

  stack<int> stk;
  auto it = a.begin();
 
  string ans{};
  for(int cur = 1; cur <= n; cur++){
    stk.push(cur);
    ans += '+';
    while(stk.size() && stk.top() == *it){
      stk.pop();
      ans += '-';
      it++;
    }
  }
  
  if(ans.size() != 2*n){
    cout << "NO";
    return 0;
  }

  for(char &c : ans) cout << c << '\n';
}