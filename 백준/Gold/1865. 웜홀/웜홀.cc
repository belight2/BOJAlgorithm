// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  이 문제는 출발점이 정해져있지 않고 negative cycle이 있는지 묻고있는 문제입니다.

  모든 정점을 출발점으로 보고 거리 테이블을 0으로 초기화한 상태로 벨만-포드를 시작합니다.

  음수 가중치를 가진 간선 정보만 갱신이 됩니다.
  
  만약, negative cycle을 있다면 n번째 완화에서 거리 테이블이 갱신이 됩니다.
*/
using namespace std;

using ll = long long;
using ti = tuple<int, int, int>;

int n, m, w;

void solve(){
  // input & init 
  cin >> n >> m >> w;

  // init
  vector<ti> edges; // 간선 정보
  vector<ll> d(n+1); // 거리 배열

  // 간선 정보 
  while(m--){
    int s, e, t;
    cin >> s >> e >> t;

    edges.push_back({s, e, t});
    edges.push_back({e, s, t});
  }

  // 웜홀 정보
  while(w--){
    int s, e, t;
    cin >> s >> e >> t;

    edges.push_back({s, e, -t});
  }

  string ans = "NO";

  // Bellman-Ford Algorithm
  for(int i = 0; i < n; i++){
    for(auto &[s, e, t] : edges){
      if(d[s] + t >= d[e]) continue;
      
      d[e] = d[s] + t;
      if(i == n-1) ans = "YES"; // nth 완화에서 갱신이 발생
    }
  }

  // output
  cout << ans << '\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}