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

vi p(100'005, -1);
vl cp(100'005);

int find(int x) { return (p[x] < 0 ? x : p[x] = find(p[x])); }

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y || x == 0 || y == 0) return;
  if(p[x] > p[y]) swap(x, y);
  cp[x] += cp[y];
  cp[y] = 0;
  p[y] = x;
}

void war(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y || x == 0 || y == 0) return;
  if(cp[x] == cp[y]){
    cp[x] = cp[y] = p[x] = p[y] = 0;
    return;
  }
  if(cp[x] < cp[y]) swap(x, y);
  cp[x] -= cp[y];
  cp[y] = 0;
  p[y] = x;
}

int n, m;

int main() {
  fastio(nullptr, false);  

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    cp[i] = x;
  }
  
  while(m--){
    int o, x, y;
    cin >> o >> x >> y;

    if(o & 1) merge(x, y);
    else war(x, y);
  }

  vi ans{};
  for(int i = 1; i <= n; i++){
    if(cp[i] == 0 || p[i] >= 0) continue;
    ans.pb(cp[i]);
  }

  sort(all(ans));
  cout << sz(ans) << nl;
  for(auto x : ans) cout << x << ' ';
}