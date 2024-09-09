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

int n, k;
int dist[100'005];
int cnt[100'005];

int main() {
  fastio(nullptr, false);

  // input
  cin >> n >> k;

  // init
  qi q;
  q.push(n);
  dist[n] = 1;
  cnt[n] = 1;

  // solve
  while(sz(q)){
    auto cur = q.front(); q.pop();
    for(auto nxt : {cur-1, cur+1, 2*cur}){
      if(nxt < 0 || nxt > 100'000) continue;
      if(dist[nxt] == 0 || dist[nxt] > dist[cur] + 1){
        dist[nxt] = dist[cur] + 1;
        cnt[nxt] = cnt[cur];
        q.push(nxt);
      }
      else if(dist[nxt] == dist[cur] + 1){
        cnt[nxt] += cnt[cur];
      } 
    }
  }

  // output
  cout << dist[k]-1 << nl << cnt[k];
}