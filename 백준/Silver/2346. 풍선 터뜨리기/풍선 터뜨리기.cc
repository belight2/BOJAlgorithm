#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

int n;
deque<pi> dq;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    dq.push_back({x, i});
  }

  while(dq.size() > 1){
    auto [cnt, num] = dq.front(); dq.pop_front();
    cout << num << " ";
    while(cnt > 1){
      dq.push_back(dq.front());
      dq.pop_front();
      cnt--;
    }
    while(cnt < 0){
      dq.push_front(dq.back());
      dq.pop_back();
      cnt++;
    }
  }
  cout << dq.front().Y;
}