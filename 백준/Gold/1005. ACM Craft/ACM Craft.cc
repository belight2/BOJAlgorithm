#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n, k, u, v;
void solve(){
  cin >> n >> k;
  vector<vi> adj(n+1);
  vi deg(n+1), t(n+1), d(n+1);
  for(int i = 1; i <= n; i++) cin >> t[i];
  while(k--){
    cin >> u >> v;
    adj[u].pb(v);
    deg[v]++;
  }
  qi q;
  for(int i = 1; i <= n; i++){
    if(deg[i]) continue;
    q.push(i);
    d[i] = t[i];
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      d[nxt] = max(d[nxt], t[nxt] + d[cur]);
      if(!(--deg[nxt])) q.push(nxt);
    }
  }
  int ans;
  cin >> ans;
  cout << d[ans] << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t{};
  cin >> t;
  while(t--) solve();
}