#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
const char nl = '\n';
const int INF = 1e9+1;
int v, e, p;
// adj[i] = { w, j } i -> j 가는데 거리 w
vector<pi> adj[5005];
priority_queue<pi, vector<pi>, greater<pi>> pq;
int d[2][5005];
void dijstra(int *d, int st){
  d[st] = 0;
  pq.push({d[st], st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X ) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[cur.Y]+nxt.X, nxt.Y});
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e >> p;
  while(e--){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});    
  }
  memset(d, INF, sizeof(d));
  dijstra(d[0], 1); 
  dijstra(d[1], p);
  string ans = (d[0][v] == d[0][p] + d[1][v]) ? "SAVE HIM" : "GOOD BYE";
//#define DEBUG_
#ifndef DEBUG_
  cout << ans;
#endif
#ifdef DEBUG_
#endif
}