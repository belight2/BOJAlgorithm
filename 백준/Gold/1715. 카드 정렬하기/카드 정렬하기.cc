#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
const char nl = '\n';
priority_queue<int, vector<int>, greater<int>> pq;
int N;
int x;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  cin >> N;
  while(N--){
    cin >> x;
    pq.push(x);
  }
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a+b);
  }
  cout << ans;
}