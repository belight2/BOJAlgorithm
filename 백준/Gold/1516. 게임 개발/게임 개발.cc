#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int n, t[505], deg[505], ans[505];
vi adj[505];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int cur = 1; cur <= n; cur++){
    cin >> t[cur];
    int prv;
    while(cin >> prv, prv != -1){
      adj[prv].pb(cur);
      deg[cur]++;
    }
  }
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(deg[i]) continue;
    ans[i] = t[i];
    q.push(i);
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      ans[nxt] = max(ans[nxt], t[nxt] + ans[cur]);
      if(--deg[nxt] == 0){
        q.push(nxt);
      }
    }
  }
  for(int i = 1; i <= n; i++) cout << ans[i] << nl;
}