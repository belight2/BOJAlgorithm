// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m, t;
vector<int> adj[55]; 
vector<int> party[55];
bool truth[55];

void bfs(){
  queue<int> q;
  // truth 배열을 방문 배열로 사용
  for(int i = 1; i <= n; i++){
    if(truth[i]) q.push(i);
  }

  while(q.size()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(truth[nxt]) continue;
      truth[nxt] = 1;
      q.push(nxt);
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m >> t;
  
  // 진실을 아는 사람 입력
  while(t--){
    int x;
    cin >> x;
    truth[x] = 1;
  }

  // 파티에 참석하는 인원 입력
  for(int i = 0; i < m; i++){
    int cnt;
    cin >> cnt;

    int prv, cur;
    cin >> prv;
    party[i].push_back(prv);

    while(cnt-- > 1){
      cin >> cur;
      party[i].push_back(cur);
      adj[prv].push_back(cur);
      adj[cur].push_back(prv);
    }
  }

  // solve
  bfs();

  int ans{};
  for(int i = 0; i < m; i++){
    bool isknown{};
    for(int p : party[i]) if(truth[p]) isknown = 1;
    if(!isknown) ans++;
  }

  // output
  cout << ans;
}