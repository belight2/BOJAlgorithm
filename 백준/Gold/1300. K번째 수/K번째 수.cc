#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const char nl = '\n';

ll n, k;

bool solve(ll mid){
  ll cnt{};
  for(ll i = 1; i <= n; i++){
    cnt += min(mid / i, n);
  }
  return cnt < k;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> k;
  ll st{}, en = n * n + 1;
  while(st < en){
    ll mid = (st + en) / 2;
    if(solve(mid)) st = mid + 1;
    else en = mid;
  }
  cout << en;
}