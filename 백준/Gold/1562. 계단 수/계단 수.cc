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

const int MOD = 1e9;

int n;
int d[102][10][1<<10]; // d[i][j][k] : i자리 수, 마지막 자리 숫자가 j, 사용한 숫자에 대한 bit-field

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;

  // solve
  for(int i = 1; i <= 9; i++) d[1][i][1<<i] = 1;
  
  for(int i = 1; i < n; i++){
    // 마지막 자리 숫자가 0, 9인 경우를 처리
    for(int k = 0; k < (1<<10); k++){
      d[i+1][8][k | 256] = (d[i+1][8][k | 256] + d[i][9][k]) % MOD; 
      d[i+1][1][k | 2] = (d[i+1][1][k | 2] + d[i][0][k]) % MOD;
    }

    // 마지막 자리 숫자가 j라면 계단수 유지를 위해 마지막 자리수가 j-1, j+1만 와야됨
    for(int j = 1; j < 9; j++){
      for(int k = 0; k < (1<<10); k++){
        d[i+1][j-1][k | (1<<(j-1))] = (d[i+1][j-1][k | (1 << (j-1))] + d[i][j][k]) % MOD;
        d[i+1][j+1][k | (1<<(j+1))] = (d[i+1][j+1][k | (1 << (j+1))] + d[i][j][k]) % MOD;
      }
    }
  }

  // output
  int ans{};
  for(int i = 0; i < 10; i++) ans = (ans + d[n][i][(1<<10)-1]) % MOD;
  cout << ans;
}