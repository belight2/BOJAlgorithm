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

const int ROOT = 1;
const int MX = 2'400'005;

int unused = 2;
int chk[MX];
int nxt[MX][26];

const int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
const int dx[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

string board[4];
bool vis[4][4];
int mark = 2;

int sc;
int cnt;
string ans;

int ctoi(char c){ return c - 'A'; }

void insert(string &s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][ctoi(c)] == -1) nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
  }
  chk[cur] = 1;
}

void find(int cx, int cy, int cur, string s){
  if(cur == -1 || sz(s) > 8) return;
  if(chk[cur] != 0 && chk[cur] != mark){
    chk[cur] = mark;
    sc += score[sz(s)];
    cnt++;
    if(sz(ans) < sz(s)) ans = s;
    else if(sz(ans) == sz(s) && s < ans) ans = s;
  }
  
  for(int dir = 0; dir < 8; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
    if(vis[nx][ny]) continue;
    char c = board[nx][ny];
    vis[nx][ny] = 1;
    find(nx, ny, nxt[cur][ctoi(c)], s + c);
    vis[nx][ny] = 0;
  }
}

void solve(){
  sc = 0;
  ans = "";
  cnt = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      vis[i][j] = 1;
      find(i, j, nxt[ROOT][ctoi(board[i][j])], string(1, board[i][j]));
      vis[i][j] = 0;
    }
  }
  cout << sc << " " << ans << " " << cnt << nl; 
  mark++;
}
int main() {
  fastio(nullptr, false);
  memset(nxt, -1, sizeof(nxt));
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