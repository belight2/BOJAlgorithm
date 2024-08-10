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

const int inf = 1e9+5;

int n, m;
int mn[200'005], mx[200'005];

pi query(int l, int r){
  pi ret{inf, 0};
  for(l += n, r += n; l < r; l>>=1, r>>=1){
    if(l&1) ret = {min(ret.X, mn[l]), max(ret.Y, mx[l++])};
    if(r&1) ret = {min(ret.X, mn[r-1]), max(ret.Y, mx[--r])};
  }
  return ret;
}
int main() {
  fastio(nullptr, false);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    mx[n+i] = mn[n+i] = x;
  }
  
  for(int i = n-1; i > 0; --i){
    mx[i] = max(mx[i<<1], mx[i<<1|1]);
    mn[i] = min(mn[i<<1], mn[i<<1|1]);
  }

  while(m--){
    int a, b;
    cin >> a >> b;
    auto ans = query(a-1, b);
    cout << ans.X << ' ' << ans.Y << nl;
  }

}