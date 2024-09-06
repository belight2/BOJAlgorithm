#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const char nl = '\n';
int N, x;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N*N; i++){
    cin >> x;
    pq.push(x);
    if(pq.size() > N) pq.pop();
  }
  cout << pq.top();
}