#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

int n, m, t, u, v, w;
vti edges;

// disjoint-set
vi p(10005, -1);

int find(int x){
  return (p[x] < 0 ? x : p[x] = find(p[x]));
}

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] == p[y]) p[x]--;
  if(p[x] < p[y]) p[y] = x;
  else p[x] = y;
}

int main() {
  fastio(nullptr, false);
  cin >> n >> m >> t;
  while(m--){
    cin >> u >> v >> w;
    edges.pb({w, u, v});
  }
  sort(all(edges));
  ll ans{}, cnt{};
  for(auto &cur : edges){
    auto &[c, a, b] = cur;
    if(find(a) == find(b)) continue;
    merge(a, b);
    cnt++;
    ans += c;
    if(cnt == n-1) break;
  }
  cnt = (n < 3 ? 1 : (n-2) * (n-1) / 2);
  cout << ans + cnt * t; 
}