// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;

void solve(){
  if(n == 1){
    cout << 0 << '\n';
    return;
  }
  
  int ans = n, prime = 2;
  while(prime * prime <= n){
    if(!(n % prime)) ans -= ans / prime;
    while(!(n % prime)) n /= prime;
    prime++;
  }
  if(n > 1) ans -= ans / n;

  // output
  cout << ans << '\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  while(cin >> n, n) solve();
}