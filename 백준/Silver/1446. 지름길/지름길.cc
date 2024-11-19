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

const int INF = 1e9;

int n, d;
int dist[10'005];
vector<pi> adj[10'005];

int main() {
  fastio(nullptr, false);

  cin >> n >> d;

  for(int i = 0; i < d; i++) adj[i].pb({i+1, 1});

  while(n--){
    int st, en, w;
    cin >> st >> en >> w;
    adj[st].pb({en, w});
  }

  fill(dist, dist + d + 1, 1e9);

  queue<int> q;
  dist[0] = 0;
  q.push(0);

  while(sz(q)){
    auto cur = q.front(); q.pop();
    for(auto [nxt, w] : adj[cur]){
      if(dist[nxt] != INF && dist[nxt] < dist[cur] + w) continue;
      dist[nxt] = dist[cur] + w;
      q.push(nxt);
    }
  }

  cout << dist[d];
}