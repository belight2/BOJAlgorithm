// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  발전소가 설치된 도시들은 서로 떨어져있지만 케이블로 연결될 필요도 없습니다.

  따라서 가상의 정점 0번을 두고 발전소가 설치된 도시들을 0번 도시가 가중치가 0인 케이블이 있다고 가정합니다.

  이를 인접리스트에 추가한다음 n+1개의 정점을 가진 그래프에서 최소 신장 트리를 구하면 됩니다.
*/
using namespace std;
using ti = tuple<int, int, int>;
using pi = pair<int, int>;

int n, m, k;
vector<pi> adj[1005];
vector<bool> chk(1005);
priority_queue<ti, vector<ti>, greater<ti>> pq;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m >> k;
  
  while(k--){
    int x; cin >> x;
    adj[0].push_back({0, x});
    adj[x].push_back({0, 0});
  }

  while(m--){
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }

  // solve
  chk[0] = 1;
  for(auto &[cost, nxt] : adj[0]) pq.push({cost, 0, nxt});

  int cnt{}, ans{};
  while(cnt < n){
    auto [cost, prv, cur] = pq.top(); pq.pop();
    if(chk[cur]) continue;
    chk[cur] = 1;
    ans += cost;
    cnt++;
    for(auto &[cost, nxt] : adj[cur]){
      if(chk[nxt]) continue;
      pq.push({cost, cur, nxt});
    }
  }

  // output
  cout << ans;
}