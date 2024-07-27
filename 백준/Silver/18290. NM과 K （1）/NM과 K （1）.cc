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
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int ans = -1e9;
int n, m, k;
int a[11][11];
bool vis[11][11];
bool chk(int x, int y){
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(vis[nx][ny]) return 1;
  }
  return 0;
}
void func(int cnt, int sum){
  if(cnt == k){
    ans = max(ans, sum);
    return;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j] || chk(i, j)) continue;
      vis[i][j] = 1;
      func(cnt+1, sum + a[i][j]);
      vis[i][j] = 0;
    }
  }
}
int main() {
  fastio(nullptr, false);
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
  for(int j = 0; j < m; j++)
    cin >> a[i][j];
  func(0, 0);
  cout << ans;
}