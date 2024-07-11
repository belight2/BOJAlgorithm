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
int sx, sy, ex, ey;
int ans[55][5];
int get_num(int row, int col){
  int n = max(abs(row), abs(col));
  int ret = (2*n+1)*(2*n+1);
  if(row == n) return ret - n + col;
  ret -= 2*n;
  if(col == -n) return ret - n + row;
  ret -= 2*n;
  if(row == -n) return ret - n - col;
  ret -= 2*n;
  return ret - n - row;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> sx >> sy >> ex >> ey;
  int i{}, j{};
  for(int row = sx; row <= ex; row++){
    for(int col = sy; col <= ey; col++){
      ans[i][j++] = get_num(row, col);
    }
    i++; j = 0;
  }
  int rmx = ex - sx + 1;
  int cmx = ey - sy + 1;
  int sz = to_string(*max_element(&ans[0][0], &ans[rmx][cmx])).size();
  for(int i = 0; i < rmx; i++){
    for(int j = 0; j < cmx; j++){
      for(int k = to_string(ans[i][j]).size(); k < sz; k++) cout << ' ';
      cout << ans[i][j] << ' ';
    }
    cout << nl;
  }

}