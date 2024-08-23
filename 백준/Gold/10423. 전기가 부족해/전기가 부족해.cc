#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
const char nl = '\n';
int N, M, K, u, v, w;
int c;
vector<int> p(1005, -1);
vector<tuple<int, int, int>> cable;
int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}
bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  if(p[x] < p[y]) p[y] = x;
  else p[x] = y;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  vector<int> k(K);
  int cnt = 0, ans = 0;
  cin >> k[0];
  for(int i = 1; i < K; i++){
    cin >> k[i];
    if(merge(k[0], k[i])) cnt++;
  }
  while(M--){
    cin >> u >> v >> w;
    cable.push_back({w, u, v});
  }
  sort(cable.begin(), cable.end());
  for(auto cur : cable){
    if(cnt == N - 1) break;
    tie(w, u, v) = cur;
    if(!merge(u, v)) continue;
    ans += w;
    cnt ++;
  }
  cout << ans;
}