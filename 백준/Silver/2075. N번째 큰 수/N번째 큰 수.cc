// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input & solve
  cin >> n;
  for(int i = 0; i < n*n; i++){
    int x;
    cin >> x;
    pq.push(x);
    /*
      우선순위 큐에 n개의 데이터만 저장하여
      메모리 사용량을 유지합니다.
    */
    if(pq.size() > n) pq.pop();
  }

  // output
  cout << pq.top();
}