// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

// priority_queue<int> pq : 이렇게만 선언한 경우, 최대힙이다.
// 최소 힙을 사용하고 싶으면 <vector>헤더와 <functional>헤더를 include한 뒤, 아래와 같이 선언해야 한다.
priority_queue<int, vector<int>, greater<int>> pq;
int n, x;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;

  // solve & output
  // 우선순위큐도 비어있는데 top()이나 pop()을 하면 런타임 에러가 발생함.
  while(n--){
    cin >> x;
    if(x) pq.push(x);
    else if(pq.empty()) cout << 0 << '\n';
    else{
      cout << pq.top() << '\n';
      pq.pop();
    }
  }
}