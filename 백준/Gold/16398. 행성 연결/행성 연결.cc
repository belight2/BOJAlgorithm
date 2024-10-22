// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ti = tuple<int,int,int>;

int n;
vector<ti> edge; // 간선 정보
vector<int> p(1005, -1); // 부모 정보

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0; // 유니온 실패
  if(p[x] == p[y]) --p[x];
  if(p[x] > p[y]) swap(x, y);
  p[y] = x;
  return 1; // 유니온 성공
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 1; i <= n; i++){
    int cost;
    for(int j = 1; j <= n; j++){
      cin >> cost;
      if(i >= j) continue;
      edge.push_back({cost, i, j});
    }
  }

  // solve
  int cnt{};
  long long ans{};
  sort(edge.begin(), edge.end());
  for(auto &[cost, u, v] : edge){
    if(!merge(u, v)) continue; // 유니온 실패 시 넘어감
    cnt++;
    ans += cost;
    if(cnt == n-1) break; // 간선을 n-1개 선택했으면 루프를 종료
  }

  // output
  cout << ans;
}