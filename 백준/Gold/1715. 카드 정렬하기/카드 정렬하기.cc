// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  while(n--){
    cin >> x;
    pq.push(x);
  }

  // solve
  int ans{};
  while(pq.size() > 1){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a+b);
  }

  // output
  cout << ans;
}