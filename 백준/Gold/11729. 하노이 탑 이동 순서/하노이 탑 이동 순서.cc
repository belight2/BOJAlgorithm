// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using pi = pair<int,int>;
#define X first
#define Y second

int n;
vector<pi> path; // 이동 경로
int time_complexity; // 시간복잡도

void hanoi(int a, int b, int c, int n){
  if(n == 1){
    time_complexity++; // 시간복잡도 증가
    path.push_back({a, c}); // 경로 추가
    return;
  }
  hanoi(a, c, b, n-1);
  time_complexity++; // 시간복잡도 증가
  path.push_back({a, c}); // 경로 추가
  hanoi(b, a, c, n-1);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;

  // solve
  hanoi(1, 2, 3, n);

  // output
  cout << time_complexity << '\n';
  for(auto &cur : path) cout << cur.X << ' ' << cur.Y << '\n';
}