#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
const int INF = 0x3f3f3f3f;
priority_queue<pi, vector<pi>, greater<pi>> pq;
int n, m, t, v;
vector<int> adj[10005];
int d[10005];
int w[10005];
int deg[10005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fill(d, d+n+1, INF);
  for(int i = 1; i <= n; i++){
    cin >> t >> m;
    w[i] = t;
    while(m--){
      cin >> v;
      deg[v]++;
      adj[i].pb(v);
    }
  }
  for(int i = 1; i <= n; i++)
    if(!deg[i]){
      pq.push({w[i], i});
      d[i] = w[i];
    }
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    d[cur.Y] = min(d[cur.Y], cur.X);
    for(auto nxt : adj[cur.Y]){
      if(--deg[nxt]) continue;
      pq.push({w[nxt]+cur.X, nxt});
    }
  }
  cout << *max_element(d+1, d+n+1);
}