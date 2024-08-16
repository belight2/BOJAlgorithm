#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = 1e7;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  vector<bool> is_prime(MX, 1);
  is_prime[1] = 0;
  for(ll i = 2; i * i <= MX; i++){
    if(!is_prime[i]) continue;
    for(ll j = i * i; j <= MX; j += i) is_prime[j] = 0;
  }
  ll a, b;
  cin >> a >> b;

  int ans{};
  for(ll i = 2; i * i <= b; i++){
    if(!is_prime[i]) continue;
    ll cur = i;
    while(cur <= b / i){
      cur *= i;
      ans += a <= cur;
    }
  }
  cout << ans;
}