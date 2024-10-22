// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  무방향 가중치 연결 그래프입니다.

  정복할 때마다 t만큼 모든 도로의 비용이 증가하지만

  모든 도시를 정복해야 하므로 추가되는 비용은 정점의 개수에 비례하게 증가합니다.

  따라서 MST가 되는 간선들의 가중치의 합과 정점의 개수에 맞추어 추가 비용을 더해주시면 됩니다.
*/
using namespace std;

using ti = tuple<int,int,int>;

int n, m, t;
vector<ti> edges;
vector<int> p(10005, -1);

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
  cin >> n >> m >> t;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  // solve
  long long ans{}, cnt{};
  sort(edges.begin(), edges.end());
  for(auto &[cost, u, v] : edges){
    if(!merge(u, v)) continue;
    cnt++;
    ans += cost;
    if(cnt == n - 1) break;
  }

  // cnt값 조정
  cnt = (n-2) * (n-1) / 2;
  
  // output
  cout << ans + cnt * t;
}