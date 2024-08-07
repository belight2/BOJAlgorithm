#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
#define X first
#define Y second

int n;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;

  vector<int> ans(n, -1);
  stack<pi> stk;
  int cur;

  for(int i = 0; i < n; i++){
    cin >> cur;
    while(stk.size() && stk.top().X < cur){
      ans[stk.top().Y] = cur;
      stk.pop();
    }
    stk.push({cur, i});
  }

  for(auto &x : ans) cout << x << ' ';  
}