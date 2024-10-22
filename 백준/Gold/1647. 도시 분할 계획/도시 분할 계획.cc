// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ti = tuple<int,int,int>;

int n, m;
vector<ti> edge;
vector<int> p(100005, -1);

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  if(p[x] == p[y]) p[x]--;
  if(p[x] > p[y]) swap(x, y);
  p[y] = x;
  return 1;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  while(m--){
    int u, v, c;
    cin >> u >> v >> c;
    edge.push_back({c, u, v});
  }

  // solve
  sort(edge.begin(), edge.end());
  int town = n; // 현재 분리된 마을의 개수
  int ans{}; // 유지비의 최솟값
  for(auto &[cost, u, v] : edge){
    if(town == 2) break; // 분리된 마을이 2개면 패스
    if(!merge(u, v)) continue;
    town--;
    ans += cost;
  }

  // output
  cout << ans;
}