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

const ll MOD = 1e9 + 7;

ll rpow(int a, int x){
  if(x == 1) return a; 
  ll ret = rpow(a, x/2);
  ret = (ret * ret) % MOD;
  if(x&1) ret = (ret * a) % MOD;
  return ret;
}

int main() {
  fastio(nullptr, false);
  
  // input & solve
  ll m, n, s, ans{};
  cin >> m;
  while(m--){
    cin >> n >> s;
    if(s%n)
    ans = (ans + (s * rpow(n, MOD-2)) % MOD) % MOD;
  }

  // output
  cout << ans;
}