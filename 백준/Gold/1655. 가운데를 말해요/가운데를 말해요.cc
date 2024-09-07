// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

/*
  현재 입력으로 들어오는 데이터가 아래와 같다고 하자.

  데이터 : [ 1, 2, 3, 4, 5, 6, 7 ]
  
  두 개의 우선순위 큐를 선언해 아래와 같이 데이터를 저장한다.

  l = [ 1, 2, 3, 4 ]
  r = [ 5, 6, 7 ]
  
  l.top()은 항상 가운데 값을 가지게 한다.
*/

int n;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  
  // solve & output
  int cur;
  while(n--){
    cin >> cur;
    (l.size() <= r.size()) ? l.push(cur) : r.push(cur);

    // 이전 데이터는 이미 올바르게 삽입이 되어있음
    // 현재0 데이터의 값이 반대로 들어갔으니
    // 최대 힙과 최소 힙의 top()을 swap
    if(r.size() && l.top() > r.top()){
      l.push(r.top());
      r.pop();
      r.push(l.top());
      l.pop();
    }

    cout << l.top() << '\n';
  }
}