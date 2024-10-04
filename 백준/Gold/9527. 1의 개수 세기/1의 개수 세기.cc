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

ull d[60];
ll a, b;

ll cal(ull x){
  ll ans = x & 1;
  for(int i = 55; i > 0; i--){
    if((x >> i) & 1){
      ans += d[i-1] + (x - (1LL << i) + 1);
      x -= (1LL << i);
    }
  }
  return ans;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> a >> b;

  // solve
  d[0] = 1;
  for(int i = 1; i < 55; i++){
    d[i] = 2 * d[i-1] + (1LL << i);
  }

  // ouptut
  cout << cal(b) - cal(a-1);
}