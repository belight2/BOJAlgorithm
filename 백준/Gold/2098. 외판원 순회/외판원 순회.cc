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

const int INF = 1e9;
int n;
int adj[17][17];
int d[17][1<<17];

int TSP(int cur, int mask){
  if(d[cur][mask] != -1) return d[cur][mask];
  if(mask == (1 << (n+1)) - 1 ) return (adj[cur][1] != 0 ? adj[cur][1] : INF);
  
  d[cur][mask] = INF;
  for(int nxt = 1; nxt <= n; nxt++){
    if(mask & (1<<nxt) || adj[cur][nxt] == 0) continue;
    d[cur][mask] = min(d[cur][mask], TSP(nxt, mask | (1 << nxt)) + adj[cur][nxt]);
  }
  
  return d[cur][mask];
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> adj[i][j];
    }
  }
  
  // solve
  memset(d, -1, sizeof(d));
  cout << TSP(1, 3);
}