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

int n, m, k;
vl p(30005);
vi c(30005, 1);

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  c[x] += c[y];
  c[y] = 0;
  p[x] += p[y];
  p[y] = x;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++){
    ll candy;
    cin >> candy;
    p[i] = -candy;
  }
  while(m--){
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }

  // solve
  ll d[3005]{};
  vb chk(30005);
  for(int i = 1; i <= n; i++){
    int cur = find(i);
    if(c[cur] ==  0 || chk[cur]) continue;
    chk[cur] = 1;
    for(int j = k - 1; j >= c[cur]; j--){
      d[j] = max(d[j], d[j-c[cur]] - p[cur]);
    }
  }
  // output
  cout << *max_element(d, d+k);
}