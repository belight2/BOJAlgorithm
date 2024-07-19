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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n, ans;
int main() {
  fastio(nullptr, false);
  cin >> n;
  vpi pos(n);
  for(pi &cur : pos) cin >> cur.X >> cur.Y;
  auto [tx, ty] = pos[0];
  for(int i = 1; i < n; i++){
    auto [cx, cy] = pos[i];
    if(tx <= cx && cx <= ty ) ty = max(ty, cy);
    else{
      ans += ty - tx;
      tx = cx;
      ty = cy;
    }
  }
  ans += ty - tx;
  cout << ans;
}