#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
vector<int> bp(1005, -1);
vector<int> wp(1005, -1);
int find(vector<int> &p, int x){
  if(p[x] < 0) return x;
  return p[x] = find(p, p[x]);
}
bool merge(vector<int> &p, int u, int v){
  u = find(p, u);
  v = find(p, v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<tuple<int,int,int>> road;
  int n{}, m{};
  int a{}, b{}, c{};
  cin >> n >> m;
  cin >> a >> b >> c;
  int wst{}, bst{};
  merge(bp, a, b); bst += (c+1)%2;
  merge(wp, a, b); wst += (c+1)%2;
  while(m--){
    cin >> a >> b >> c;
    road.push_back({(c+1)%2, a, b});
  }
  sort(road.begin(), road.end());
  int best{}, worst{};
  for(int i = 0; i < road.size(); i++){
    auto cur = road[i];
    tie(c, a, b) = cur;
    if(!merge(bp, a, b)) continue;
    bst += c;
    best++;
    if(best == n-1) break;
  }
  for(int i = road.size()-1; i >= 0; i--){
    auto cur = road[i];
    tie(c, a, b) = cur;
    if(!merge(wp, a, b)) continue;
    wst += c;
    worst++;
    if(worst == n-1) break;
  }
  cout << wst * wst - bst * bst;
}