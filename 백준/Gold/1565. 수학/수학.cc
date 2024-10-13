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

int n, m;
ll a[55], b[55];

int main() {
  fastio(nullptr, false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i];

  // 배열 b의 최대 공약수를 구한다.
  int g = b[0];  
  for(int i = 1; i < m; i++) g = gcd(g, b[i]);

  // solve
  // 최대 공약수의 약수를 구한다.
  vl divisor;
  for(ll i = 1; i * i <= g; i++){
    if(g%i) continue;
    int t = g / i;
    divisor.pb(i);
    if(t != i) divisor.pb(t);
  }

  ll ans{};
  sort(all(divisor));  
  for(auto x : divisor){
    bool chk = 1;
    for(int i = 0; i < n; i++){
      if(x % a[i] == 0) continue;
      chk = 0;
      break;
    }
    if(chk) ans++;
  }

  // output
  cout << ans;
}