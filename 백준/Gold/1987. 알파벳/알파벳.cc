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

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int r, c;
string board[22];
bool chk[26];
int ans;

// 비둘기집 원리
void dfs(int cx, int cy, int dep){
  bool flag{};
  for(int dir = 0; dir < 4; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    if(chk[board[nx][ny]-'A']) continue;
    flag = 1;
    chk[board[nx][ny] -'A'] = 1;
    dfs(nx, ny, dep+1);
    chk[board[nx][ny] - 'A'] = 0;
  }
  if(!flag) ans = max(ans, dep);
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> r >> c;
  for(int i = 0; i < r; i++) cin >> board[i];

  chk[board[0][0]-'A'] = 1;
  dfs(0, 0, 1);  
  cout << ans;
}