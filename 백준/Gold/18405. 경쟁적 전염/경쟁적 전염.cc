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

int n, k, s, x, y;
int board[205][205];
priority_queue<ti, vector<ti>, greater<ti>> pq[2];

int main() {
  fastio(nullptr, false);
  
  // input
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j]) pq[0].push({board[i][j], i, j});
    }
  }
  cin >> s >> x >> y;

  // solve
  for(int i = 0; i < s; i++){
    int cur = i%2;
    int nxt = (cur + 1) % 2;
    while(sz(pq[cur])){
      auto [state, cx, cy] = pq[cur].top(); pq[cur].pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny]) continue;  
        board[nx][ny] = state;
        pq[nxt].push({board[nx][ny], nx, ny});
      }
    }
  }
  
  // output
  cout << board[x-1][y-1];
}