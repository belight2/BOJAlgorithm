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

// down, right, up, left
const int dx[4] = {1, 0, -1, 0}; 
const int dy[4] = {0, 1, 0, -1};

int r, c, t;
int room[55][55];
vpi ac_pos; // 공기 청정기 위치 [0] : 위 , [1] : 아래

// 미세먼지 확산을 구현 O(r*c)
void spread(){
  vti dust_pos;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(room[i][j] > 0) dust_pos.pb({room[i][j], i, j});
    }
  }

  for(auto &cur : dust_pos){
    auto &[dust, cx, cy] = cur;
    int spread_dust = dust / 5;
    int cnt{};
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(room[nx][ny] == -1) continue;
      cnt++;
      room[nx][ny] += spread_dust;
    }
    room[cx][cy] -= cnt * spread_dust;
  }
}

// 바람에 따라 미세먼지를 밀어낸다. 
void move(int &px, int &py, int dir, bool sign){
  int cx = px + dx[dir];
  int cy = py + dy[dir];
  while(room[cx][cy] != -1){
    if((sign ? 0 : ac_pos[1].X) > cx || cx >= (sign ? ac_pos[1].X : r) || cy < 0 || cy >= c) return;
    if(room[px][py] == -1) room[cx][cy] = 0;
    else room[px][py] = room[cx][cy];
    px = cx;
    py = cy;
    cx += dx[dir];
    cy += dy[dir];
  } 
  if(room[cx][cy] == -1) room[px][py] = 0;
}

// 공기 청정지 작동
void operate(){
  auto [cx, cy] = ac_pos[0];
  for(int dir = 2; dir > -2; dir--) move(cx, cy, (dir+4)%4, 1);
  
  tie(cx, cy) = ac_pos[1];
  for(int dir = 0; dir < 4; dir++) move(cx, cy, dir, 0);
}

int main() {
  fastio(nullptr, false);

  //input
  cin >> r >> c >> t;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> room[i][j];
      if(room[i][j] == -1) ac_pos.pb({i, j});
    }
  }
  
  // solve
  while(t--){
    spread();
    operate();
  }
  
  // output
  cout << accumulate(&room[0][0], &room[r][c], 2); 
}