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

const int FIND_IT = 1e9; // 문서를 찾았는가

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int n, m;
char board[105][105];
bool vis[105][105];
bool is_ownKey[30];

string own_key;

bool is_enter(char c, int x, int y){ return ((c == '.' || islower(c) || c == '$') and ((x == 0 || x == n-1) || (y == 0 || y == m-1))); }

// 열쇠랑 키를 모두 '.'로 바꿈
void open_door(vpi (&door)[], vpi &enter, string &keys){
  for(auto key : keys){
    int idx = key - 'a';
    if(key == '0' || is_ownKey[idx]) continue;
    is_ownKey[idx] = 1;
    for(auto &[x, y] : door[idx]){
      board[x][y] = '.';
      if(is_enter('.', x, y)) enter.pb({x, y});
    }
  }
}

pi bfs(vpi (&door)[], vpi &enter){
  memset(vis, 0, sizeof(vis));
  string cur_keys{};
  int cnt{}, ans{};
  
  qpi q;
  for(auto &[x, y] : enter){
    cnt++;
    q.push({x, y});
    vis[x][y] = 1;
    if(board[x][y] == '$') ans++;
    if(islower(board[x][y])) cur_keys.pb(board[x][y]);
  }

  while(sz(q)){
    auto [cx, cy] = q.front(); q.pop();
    
    for(int dir = 0; dir < 4; dir++){
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '*' || vis[nx][ny]) continue;
      if(isupper(board[nx][ny])) continue;

      if(board[nx][ny] == '$') ans++;
      if(islower(board[nx][ny])) cur_keys.pb(board[nx][ny]);
      
      cnt++;
      q.push({nx, ny});
      vis[nx][ny] = 1;
    }
  }

  open_door(door, enter, cur_keys);

  return {cnt, ans};
}

void solve(){
  // init
  memset(is_ownKey, 0, sizeof(is_ownKey));
  vpi door[30]; // 문의 위치
  vpi enter; // 입출구 위치

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(isupper(board[i][j]) || islower(board[i][j])) door[toupper(board[i][j]) - 'A'].pb({i, j});
      if(is_enter(board[i][j], i, j)) enter.pb({i, j});
    }
  }


  cin >> own_key;
  
  // solve
  open_door(door, enter, own_key);
  int prv{}, cur{}, ans{};
  do{
    prv = cur;
    tie(cur, ans) = bfs(door, enter);
  } while(prv != cur);

  // output
  cout << ans << nl;
}

int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}