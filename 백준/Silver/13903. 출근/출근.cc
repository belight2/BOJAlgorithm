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
const int INF = 0x3f3f3f3f;
int main() {
  fastio(nullptr, false);
  int n, m, r;
  cin >> n >> m;
  vector<vi> board(n, vi(m));
  vector<vi> dist(n, vi(m, INF));
  for(auto &row : board)
    for(auto &col : row) 
      cin >> col;
  cin >> r;
  vpi dxy(r);
  for(auto &cur : dxy) cin >> cur.X >> cur.Y;
  qpi q;
  for(int i = 0; i < m; i++){
    if(!board[0][i]) continue;
    dist[0][i] = 0;
    q.push({0, i});
  }
  while(!q.empty()){
    auto [cx, cy] = q.front(); q.pop();
    for(auto &dir : dxy){
      int nx = cx + dir.X;
      int ny = cy + dir.Y;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if((!board[nx][ny]) || dist[nx][ny] <= dist[cx][cy] + 1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
    }
  }
  int ans = *min_element(all(dist[n-1]));
  cout << (ans == INF ? -1 : ans); 
}