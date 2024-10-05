#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
const char nl = '\n';
int n;
vector<tuple<int,int,int>> edge;
vector<int> p(1005, -1);
int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}
bool merge(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int cost;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> cost;
      if(i >= j) continue;
      edge.push_back({cost, i, j});
    }
  }
  sort(edge.begin(), edge.end());
  int cnt = 0;
  long long ans = 0;
  for(auto cur : edge){
    int cost, u, v;
    tie(cost, u, v) = cur;
    if(!merge(u,v)) continue;
    cnt++;
    ans += cost;
    if(cnt == n - 1) break;
  }
  cout << ans;
}