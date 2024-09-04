#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const char nl = '\n';
priority_queue<int> a;
vector<vector<int>> deadLine(200'002);
int N, x, y;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> x >> y;
    deadLine[x].push_back(y);
  }
  int ans = 0;
  for(int cur = N; cur > 0; cur--){
    for(int k : deadLine[cur]) a.push(k);
    if(a.empty()) continue;
    ans += a.top();
    a.pop();
  }
  cout << ans;
}