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

int n;
int board[20][20];
// 0 : 가로, 1 : 세로, 2 : 대각선
int dp[3][20][20];

int main() {
  fastio(nullptr, false);
  
  cin >> n;
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
    cin >> board[i][j];
  

  dp[0][1][2] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(board[i][j] == 1) continue;
      dp[0][i][j] += dp[0][i][j-1] + dp[2][i][j-1]; 
      dp[1][i][j] += dp[1][i-1][j] + dp[2][i-1][j];
      if(board[i-1][j] == 0 && board[i][j-1] == 0 ) dp[2][i][j] += dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
    }
  }

  cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
}