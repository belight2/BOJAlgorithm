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

int n, m;
int dist[110];
int ladder[110];

int main() {
  fastio(nullptr, false);
  
  cin >> n >> m;
  for(int i = 1; i <= 100; i++) ladder[i] = i;
  
  n += m;
  while(n--){
    int u, v;     
    cin >> u >> v;
    ladder[u] = v;
  }
  
  memset(dist, -1, sizeof(dist));

  queue<int> q;
  dist[1] = 0;
  q.push(1);
  while(q.size()){
    auto cur = q.front(); q.pop();
    for(int dice = 1; dice <= 6; dice++){
      auto nxt = cur + dice;
      if(nxt > 100) continue;
      if(dist[nxt] != -1 && dist[nxt] <= dist[cur] + 1) continue;
      dist[nxt] = cur + dice;
      q.push(nxt);
      if(dist[ladder[nxt]] == -1 || dist[ladder[nxt]] > dist[cur]+1){
        dist[ladder[nxt]] = dist[cur] + 1;
        q.push(ladder[nxt]);
      }
    }
  }
  cout << dist[100];
}