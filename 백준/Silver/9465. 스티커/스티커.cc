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

int n;

void solve(){
  cin >> n;
  vector<vi> d(2, vi(n+1));
  for(int i = 0; i < 2; i++){
    for(int j = 1; j <= n; j++){
      cin >> d[i][j];
    }
  }
  for(int i = 2; i <= n; i++){
    for(int j = 0; j < 2; j++){
      d[j][i] += max({d[j][i-2], d[!j][i-2], d[!j][i-1]});
    }
  }
  cout << max(d[0][n], d[1][n]) << nl;
}
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}