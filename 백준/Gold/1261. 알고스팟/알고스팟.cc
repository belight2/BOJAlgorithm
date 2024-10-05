#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using ti = tuple<int,int, int>;
const char nl = '\n';
const int INF = 1e6+10;
int n, m;
int d[105][105];
int a[105][105];
string line;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool outOfBound(int x, int y){
  return x < 1 || x > n || y < 1 || y > m;
}
void dijkstra(int x, int y){
  d[x][y] = 0;
  priority_queue<ti, vector<ti>, greater<ti>> pq;
  pq.push({d[x][y], x, y});
  while(!pq.empty()){
    int cw, cx, cy;
    tie(cw, cx, cy) = pq.top(); pq.pop();
    if(d[cx][cy] != cw) continue;
    for(int dir = 0; dir < 4; dir++){
      int nx, ny;
      nx = cx+dx[dir];
      ny = cy+dy[dir];
      if(outOfBound(nx, ny)) continue;
      if(d[nx][ny] <= cw + a[nx][ny]) continue;
      d[nx][ny] = cw + a[nx][ny];
      pq.push({d[nx][ny], nx, ny}); 
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for(int i = 1; i <= n; i++){
    cin >> line;
    for(int j = 0; j < m; j++) a[i][j+1] = line[j] - '0';
  }
  for(int i = 1; i <= n; i++) fill(d[i], d[i]+m+1, INF);
  dijkstra(1, 1);
  cout << d[n][m];
}