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

const int dx[5] = { 0, -1, 1, 0, 0 };
const int dy[5] = { 0, 0, 0, 1, -1 };
const int change_dir[5] = { 0, 2, 1, 4, 3 };

int n, m, k;
ti board[105][105][105];

int fishing(int cur){
  int ret{};
  for(int i = 1; i <= n; i++){
    auto &[a, b, c] = board[cur][i][cur];
    if(c == 0) continue;
    ret = c;
    a = b = c = 0;
    return ret;
  }  
  return ret;
}

int change_pos(int dir){
  if(dir == 1 || dir == 4 ) return 1;
  if(dir == 2) return n;
  return m;
}

ti nextpos(int cx, int cy, int s, int d){
  int nx = cx + dx[d] * s;
  int ny = cy + dy[d] * s;
  if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) return {nx, ny, d};

  int q, r;
  if(d == 1) s -= cx - 1;
  if(d == 2) s -= n - cx;
  if(d == 3) s -= m - cy;
  if(d == 4) s -= cy - 1;
  q = (d <= 2 ?  (s / (n-1)) : (s / (m-1)));
  r = (d <= 2 ? (s % (n-1)) : (s % (m-1)));

  if(q&1) (d <= 2 ? cx : cy) = change_pos(change_dir[d]);
  else{
    (d <= 2 ? cx : cy) = change_pos(d);
    d = change_dir[d];
  }

  nx = cx + dx[d] * r;
  ny = cy + dy[d] * r;

  return { nx, ny, d };
} 

void move(int cur, int nxt){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(!get<2>(board[cur][i][j])) continue;
      auto [speed, dir, fsize] = board[cur][i][j];
      auto [nx, ny, nd] = nextpos(i, j, speed, dir);
      auto &[a, b, c] = board[nxt][nx][ny];
      if(c > fsize) continue;
      a = speed;
      b = nd;
      c = fsize;
    }
  }  
}

int main() {
  fastio(nullptr, false);
  
  // input
  cin >> n >> m >> k;
  while(k--){
    int x, y;
    cin >> x >> y;
    auto &[s, d, z] = board[1][x][y];
    cin >> s >> d >> z;
  }

  // solve
  int ans{};
  int fish_king = 1; // 낚시왕의 현재 위치
  while(fish_king <= m){
    ans += fishing(fish_king);
    move(fish_king, fish_king+1);
    fish_king++;
  }

  // output
  cout << ans;
}