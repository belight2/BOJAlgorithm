// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

const int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
const int dx[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

string board[4];
bool vis[4][4];
int mark = 2;

int sc, cnt;
string ans;

const int ROOT = 1;
const int MX = 2'400'005;

int unused = ROOT + 1;
int chk[MX];
int nxt[MX][26];

int idx(char c){ return c - 'A'; }

void insert(string &s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][idx(c)] == -1) nxt[cur][idx(c)] = unused++;
    cur = nxt[cur][idx(c)];
  }
  chk[cur] = 1;
}

void find(int cx, int cy, int cur, string s){
  if(cur == -1 || s.size() > 8) return;
  if(chk[cur] != 0 && chk[cur] != mark){
    chk[cur] = mark;
    sc += score[s.size()];
    cnt++;
    if(ans.size() < s.size()) ans = s;
    else if(ans.size() == s.size() && s < ans) ans = s;
  }

  for(int dir = 0; dir < 8; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
    if(vis[nx][ny]) continue;
    char c = board[nx][ny];
    vis[nx][ny] = 1;
    find(nx, ny, nxt[cur][idx(c)], s + c);
    vis[nx][ny] = 0;
  }
}

void solve(){
  sc = cnt = 0;
  ans = "";

  // 각 점을 시작 위치로 백트래킹
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      vis[i][j] = 1;
      find(i, j, nxt[ROOT][idx(board[i][j])], string(1, board[i][j]));
      vis[i][j] = 0;
    }
  }

  cout << sc << ' ' << ans << ' ' << cnt << '\n';
  mark++; // 다음 Boggle을 위해서 +1
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // init
  memset(nxt, -1, sizeof(nxt));

  // input
  int w, b;
  cin >> w;
  while(w--){
    string s;
    cin >> s;
    insert(s);
  }

  cin >> b;
  while(b--){
    for(int i = 0; i < 4; i++) cin >> board[i];
    solve();
  }
}