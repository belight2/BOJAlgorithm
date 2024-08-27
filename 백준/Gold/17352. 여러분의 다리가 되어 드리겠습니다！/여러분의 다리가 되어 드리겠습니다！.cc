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

vector<int> p(300'005, -1);

int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] == p[y]) --p[x];
  if(p[x] < p[y]) p[y] = x;
  else p[x] = y;
}

int n;

int main() {
  fastio(nullptr, false);

  cin >> n;
  for(int i = 0; i < n-2; i++){
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  
  int u1 = find(1);
  for(int u2 = 2; u2 <= n; u2++){
    if(u1 == find(u2)) continue;
    cout << u1 << " " << u2;
    return 0;
  }
}