#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int n, m, s, e;
vpl adj[10005];
bool bfs(int limit){
  vector<bool> vis(n+1);
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while(!q.empty()){
    auto cur = q.front(); q.pop(); 
    for(auto &[cost, nxt] : adj[cur]){
      if( vis[nxt] || cost < limit) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }
  return vis[e];
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  while(m--){
    ll u, v, c;
    cin >> u >> v >> c;
    adj[u].pb({c, v});
    adj[v].pb({c, u});
  }
  cin >> s >> e;
//#define DEBUG_
#ifndef DEBUG_
  int st = 0, en = 1e9+1;
  while(st+1 < en){
    int mid = (st+en)/2;
    if(bfs(mid)) st = mid;
    else en = mid;
  }
  cout << st;
#endif
#ifdef DEBUG_
#endif
}