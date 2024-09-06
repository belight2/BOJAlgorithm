// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

// stack 사용 시 주의점
// stack이 비어있는 상태에서 pop()이나 top()을 하게되면 런타임 에러가 발생합니다.
// 그래서 항상, pop(), top() 명령어 수행 전 스택이 비어있는지 확인해야 합니다.

int k, x;
stack<int> stk;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input & init
  cin >> k;
  while(k--){
    // 정수를 조건식에 넣을 경우, 0이 아닌 경우 모두 true, 0이면 false입니다.
    if(cin >> x, x) stk.push(x);
    else if(!stk.empty()) stk.pop();
  }

  // solve
  int ans{};
  while(!stk.empty()){
    ans += stk.top();
    stk.pop();
  }

  // output
  cout << ans;
}