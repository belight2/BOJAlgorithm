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

int n, m;
vi p(100'005, -1);
int ctp, hansol, k;

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] > p[y]) swap(x, y);
  p[x] += p[y];
  p[y] = x;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  cin >> ctp >> hansol >> k;

  // solve
  ctp = find(ctp);
  hansol = find(hansol);

  // 동맹 후보군을 추가한다.
  vpi candidate;
  for(int i = 1; i <= n; i++){
    if(i == ctp || i == hansol) continue;
    if(p[i] < 0) candidate.pb({abs(p[i]), i});
  }

  sort(rall(candidate));
  for(auto [ _, cur ] : candidate){
    if(k == 0) break;
    merge(ctp, cur);
    k--;
  }

  // output
  cout << abs(p[find(ctp)]);
}