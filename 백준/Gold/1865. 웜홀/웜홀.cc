#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
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
void solve(){
  vti edges;
  int n, m, w;
  cin >> n >> m >> w;
  vl dist(n+1);
  while(m--){
    int s, e, t;
    cin >> s >> e >> t;
    edges.pb({s, e, t});
    edges.pb({e, s, t});
  }
  while(w--){
    int s, e, t;
    cin >> s >> e >> t;
    edges.pb({s, e, -t});
  }
  string ans = "NO";
  for(int i = 0; i < n; i++){
    for(auto &edge : edges){
      auto &[s, e, t] = edge;
      if(dist[s] + t < dist[e]){
        dist[e] = dist[s] + t;
        if(i == n-1) ans = "YES";
      } 
    }
  }
  cout << ans << nl;
}
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}