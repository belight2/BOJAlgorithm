// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

int n, x, y;
priority_queue<int> pq;
vector<vector<int>> dead_line(200'002);

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    dead_line[x].push_back(y);
  }

  // solve
  /*
    모든 문제는 풀이하는데 단위 시간 1이 걸린다.
    데드 라인을 역순으로 우선순위 큐에 문제 당 컵라면 개수를 삽입하여
    데드 라인 전에 풀었을 때, 가장 많이 받을 수 있는 컵라면의 개수를 알 수 있다.
  */
  int ans{};
  for(int cur = n; cur > 0; cur--){
    for(int noodle : dead_line[cur]) pq.push(noodle);
    if(pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  } 

  // output
  cout << ans;
}