// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

void solve(){
  // init
  int n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;

  // input
  cin >> n;
  while(n--){
    ll x;
    cin >> x;
    pq.push(x);
  }

  // solve
  ll ans = 1;
  while(pq.size() > 1){
    ll A = pq.top(); pq.pop();
    ll B = pq.top(); pq.pop();
    ll AB = (A*B) % MOD;
    ans = (ans * AB) % MOD;
    pq.push(A*B); // 우선순위를 잃지 않게 modular 연산을 하지 않은 값을 삽입
  }

  // output
  cout << ans << '\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}