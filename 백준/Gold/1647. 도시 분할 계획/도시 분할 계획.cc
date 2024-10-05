#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
const char nl = '\n';
vector<int> p(100005, -1);
vector<tuple<int,int,int>> edge;
int n, m;
int a, b, c;
int find(int x){
  if(p[x] < 0 ) return x;
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
  cin >> n >> m;
  while(m--){
    cin >> a >> b >> c;
    edge.push_back({c,a,b});
  }
  sort(edge.begin(), edge.end());
  int town = n;
  int ans = 0;
  for(auto cur : edge){
    if(town == 2) break;
    int cost, a, b;
    tie(cost, a, b) = cur;
    if(!merge(a, b)) continue;
    town--;
    ans += cost;
  }
  cout << ans;
}