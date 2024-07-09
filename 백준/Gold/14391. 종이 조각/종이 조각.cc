#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n, m;
int board[5][5];
bool vis[25];
bool is_row(int bit, int x, int y){ return (bit >> (x*m+y)) & 1; }
int get_num(int bit, int pos){
  int cx = pos / m;
  int cy = pos % m;
  int ret = board[cx][cy];
  bool flag = is_row(bit, cx, cy);
  vis[pos] = 1;
  flag ? ++cy : ++cx;
  while(cx < n && cy < m && !vis[cx*m + cy]){
    if(flag != is_row(bit, cx, cy)) break;
    vis[cx*m + cy] = 1;
    ret *= 10;
    ret += board[cx][cy];
    flag ? ++cy : ++cx;
  }
  return ret;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string line;
    cin >> line;
    for(int j = 0; j < m; j++){
      board[i][j] = line[j] - '0';
    }
  }
  // number of case : 경우의 수
  int ans{};
  int noc = 1 << (n * m);
  for(int bit = 0; bit < noc; bit++){
    int cur{};
    fill(vis, vis+n*m, 0);
    for(int i = 0; i < n * m; i++){
      if(!vis[i]) cur += get_num(bit, i);
    }
    ans = max(ans, cur);
  }
  cout << ans;
}