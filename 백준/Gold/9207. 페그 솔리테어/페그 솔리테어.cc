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

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

const int n = 5;
const int m = 9;
string board[10];


vpi pin;
int ansX, ansY;

void func(int k, int cnt){
  if(cnt == 1){
    if(ansX == cnt){
      ansY = min(ansY, k);
      return;
    }
    ansX = cnt;
    ansY = k;
    return;
  }
  bool iscalled = 0;

  for(int i = 0; i < sz(pin); i++){
    auto [cx, cy] = pin[i];    
    if(board[cx][cy] != 'o') continue;

    for(int dir = 0; dir < 4; dir++){
      int mx = cx + dx[dir];
      int my = cy + dy[dir];
      if(mx < 0 || mx >= n || my < 0 || my >= m) continue;
      if(board[mx][my] != 'o') continue;
      int nx = mx + dx[dir];
      int ny = my + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] != '.') continue;

      iscalled = 1;
      // (mx, my)에 핀이 있고, (nx, ny)는 빈공간임
      board[cx][cy] = board[mx][my] = '.';
      board[nx][ny] = 'o';
      pin[i] = {nx, ny};
      func(k+1, cnt-1);
      board[cx][cy] = board[mx][my] = 'o';
      board[nx][ny] = '.';
      pin[i] = {cx, cy};
    }
  }

  if(!iscalled){
    if(ansX < cnt) return;
    if(ansX == cnt){
      ansY = min(ansY, k);
      return;
    }
    ansX = cnt;
    ansY = k;
    return;
  }
}

void solve(){
  ansX = ansY = 100;
  vpi ().swap(pin);  

  for(int i = 0 ; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < m; j++){
      if(board[i][j] != 'o') continue;
      pin.pb({i, j});
    }
  }

  func(0, sz(pin));

  cout << ansX << ' ' << ansY << nl;
}

int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}