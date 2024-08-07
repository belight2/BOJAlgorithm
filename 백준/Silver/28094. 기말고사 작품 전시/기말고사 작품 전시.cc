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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
void solve(){
  int n{}, m{}, a[10][10];
  cin >> n >> m;
  vi work(n);
  memset(a, 0, sizeof(a));
  iota(all(work), 1);
  while(m--){
    int v, x, y;
    cin >> v >> x >> y;
    a[x][y] += v; 
  }
  int mx = -1, cnt{};
  do {
    int cur{};
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        cur += a[work[i]][work[j]];
      }
    }
    if(cur > mx){ mx = cur; cnt = 1;}
    else if(cur == mx) cnt++;
  } while (next_permutation(all(work))) ;
  cout << mx << ' ' << cnt << nl;
} 
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}