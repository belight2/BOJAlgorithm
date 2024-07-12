#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n, st;
int adj[15][15];
bool vis[15];
int ans = 0x3f3f3f3f;
int cost = 0;
void solve(int cur, int k){
  if(k == n){
    ans = min(ans, cost);
    return;
  }
  for(int nxt = 0; nxt < n; nxt++){
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    cost += adj[cur][nxt];
    solve(nxt, k+1);
    vis[nxt] = 0;
    cost -= adj[cur][nxt];
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> st;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++) cin >> adj[i][j];
  
  for(int k = 0; k < n; k++)
  for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

  vis[st] = 1;
  solve(st, 1);
  cout << ans;
}