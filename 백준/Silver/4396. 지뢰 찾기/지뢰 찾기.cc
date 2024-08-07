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
const int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int n;
string board[11];
bool vis[11][11];
char ans[11][11];
int main() {
  fastio(nullptr, false);
  cin >> n;
  
  for(int i = 0; i < n; i++) cin >> board[i];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char state;
      cin >> state;
      vis[i][j] = (state == 'x') ? 1 : 0;
    }
  }
  bool is_bomb{};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!vis[i][j]){
        ans[i][j] = '.';    
        continue;    
      }
      if(board[i][j] == '*') is_bomb = 1;
      int cnt{};
      for(int dir = 0; dir < 8; dir++){
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny] == '*') cnt++;
      }
      ans[i][j] = cnt + '0';
    }
  }

  if(is_bomb){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(board[i][j] == '*'){
          ans[i][j] = '*';
        }
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << ans[i][j];
    }
    cout << nl;
  }
}