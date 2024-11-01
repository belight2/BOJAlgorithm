// Authored by : chjh2129
#include <bits/stdc++.h>
#define X first
#define Y second
/*
  각 도시에서 면접장으로 가는 거리를 구하면 TLE,

  반대로 면접장에서 각 도시로 가는 거리를 구하는 방법을 채택

  간선 정보의 방향을 거꾸로 저장한 다음, 면접장이 배치된 도시를 우선순위 큐에 모두 넣고 다익스트라 진행
*/
using namespace std;

using ll = long long;
using pi = pair<ll, int>;

const ll INF = 1e10 + 10;

int n, m, k;
ll d[100'005];
vector<pi> adj[100'005];
priority_queue<pi, vector<pi>, greater<pi>> pq;

void dijkstra(){
  while(!pq.empty()){
    auto [cw, cx] = pq.top(); pq.pop();

    if(d[cx] != cw) continue;

    for(auto [nw, nx] : adj[cx]){
      if(d[nx] <= d[cx] + nw) continue;
      d[nx] = d[cx] + nw;
      pq.push({d[nx], nx});
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input & init
  cin >> n >> m >> k;
  
  int u, v;
  ll w;
  while(m--){
    cin >> u >> v >> w;
    adj[v].push_back({w, u});
  }

  fill(d, d + n + 1, INF);

  while(k--){
    int x; cin >> x;
    d[x] = 0;
    pq.push({d[x], x});
  }

  // solve
  dijkstra();

  // output
  ll aidx = max_element(d + 1, d + n + 1) - d;
  cout << aidx << '\n' << d[aidx];
}