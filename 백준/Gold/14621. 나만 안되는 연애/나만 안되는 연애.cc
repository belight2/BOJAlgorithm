#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
vector<int> p(10005, -1);
int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}
bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  if(p[x] == p[y]) p[x]--;
  if(p[x] < p[y]) p[y] = x;
  else p[x] = y;
  return 1;
}
int n, m, u, v, d;
char gender[1005];
vti edge;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> gender[i];
  while(m--){
    cin >> u >> v >> d;
    edge.pb({d, u, v});
  }
  sort(all(edge));
  int ans{};
  int cnt{};
  for(auto cur : edge){
    auto &[c, x, y] = cur;
    if(gender[x] == gender[y]) continue;
    if(!merge(x, y)) continue;
    ans += c;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << ( cnt != n - 1 ? -1 : ans );
}