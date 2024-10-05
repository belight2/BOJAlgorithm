#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using pi = pair<int,int>;
using pqp = priority_queue<pi, vector<pi>, greater<pi>>;
const char nl = '\n';
int n, d, c, a, b, s;
void solve(){
  cin >> n >> d >> c;
  vector<vector<pi>> adj(n+1);
  vector<int> vis(n+1, -1);
  while(d--){
    cin >> a >> b >> s;
    adj[b].pb({s, a});
  }
  pqp pq;
  vis[c] = 0;
  pq.push({0, c});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    for(auto nxt : adj[cur.Y]){
      if(vis[nxt.Y] != -1 && vis[nxt.Y] <= nxt.X + cur.X) continue;
      vis[nxt.Y] = cur.X + nxt.X;
      pq.push({cur.X + nxt.X, nxt.Y}); 
    }
  }
  int last_time = *max_element(vis.begin(), vis.end());
  int cnt = count_if(vis.begin(), vis.end(), [](int x){return x != -1;});
  cout << cnt << ' ' << last_time << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
}