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

int t, n, m;
int a[1005], b[1005];

int main() {
  fastio(nullptr, false);
  
  // input
  cin >> t >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    a[i] += a[i-1];
  }
  cin >> m;
  for(int i = 1; i <= m; i++){
    cin >> b[i];
    b[i] += b[i-1];
  }

  // solve
  vi A, B; // 모든 부배열의 합을 저정할 예정
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < i; j++){
      A.pb(a[i] - a[j]);
    }
  }

  for(int i = 1; i <= m; i++){
    for(int j = 0; j < i; j++){
      B.pb(b[i] - b[j]);
    }
  }

  sort(all(B));

  ll ans{};
  for(auto cur : A){
    ans += upper_bound(all(B), t - cur) - lower_bound(all(B), t - cur);
  } 

  // output
  cout << ans;
}