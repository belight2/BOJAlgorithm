#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;

  ll ans = n;
  ll prime = 2;
  while(prime * prime <= n){
    if(!(n % prime)) ans -= ans / prime;
    while(!(n % prime)) n /= prime;
    prime++;
  }
  if(n > 1) ans -= ans / n;
  cout << ans;
}