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

// 정점 st에서 가장 먼 정점의 번호를 반환
int bfs(int st){
  memset(dist, -1, sizeof(dist));

  qi q;
  q.push(st);
  dist[st] = 0;
  while(sz(q)){
    auto cur = q.front(); q.pop();
    for(auto &[w, nxt] : adj[cur]){
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + w;
      q.push(nxt);
    }
  }

  return max_element(dist, dist+n+1) - dist;
}


int main() {
  fastio(nullptr, false);

  // input
  int u, v, w;
  while(cin >> u >> v >> w){
    n = max({u, v, n});
    adj[u].pb({w, v});
    adj[v].pb({w, u});
  }

  // output
  cout << dist[bfs(bfs(n))];
}