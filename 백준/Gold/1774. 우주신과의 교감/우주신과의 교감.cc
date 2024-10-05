#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cmath>
#define X first
#define Y second
#define ll long long
using namespace std;
const char nl = '\n';
int n, m;
vector<int> p(1005, -1);
vector<tuple<ll,int, int>> link;
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
  cin >> n >> m;
  vector<pair<int,int>> pos(n+1);
  for(int i = 1; i <= n; i++) cin >> pos[i].X >> pos[i].Y;
  int cnt = 0;
  while(m--){
    int x, y;
    cin >> x >> y;
    if(merge(x,y)) cnt++;
  }
  for(int i = 1; i <= n-1; i++){
    for(int j = i + 1; j <= n; j++){
      ll dx = pos[i].X - pos[j].X;
      ll dy = pos[i].Y - pos[j].Y;
      ll len = dx*dx + dy*dy;
      link.push_back({len, i, j});
    }
  }
  sort(link.begin(), link.end());
  double ans{};
  for(auto cur : link){
    if(cnt == n - 1) break;
    ll len; int a, b;
    tie(len, a, b) = cur;
    if(!merge(a,b)) continue;
    cnt++;
    ans += sqrt(len);
  }
  cout << fixed;
  cout.precision(2);
  cout << ans;
}