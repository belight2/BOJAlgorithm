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

int n;
vpi adj[10005];
int dist[10005];

int bfs(int st){
  fill(dist, dist+n+1, -1);
  
  queue<int> q;
  dist[st] = 0;
  q.push(st);
  while(sz(q)){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(dist[nxt.Y] != -1) continue;
      dist[nxt.Y] = dist[cur] + nxt.X;
      q.push(nxt.Y);
    }
  }
  
  return max_element(dist, dist+n+1) - dist;
}

int main() {
  fastio(nullptr, false);

  cin >> n;
  for(int i = 0; i < n-1; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].pb({w, v});
    adj[v].pb({w, u});
  }

  cout << dist[bfs(bfs(1))];
}