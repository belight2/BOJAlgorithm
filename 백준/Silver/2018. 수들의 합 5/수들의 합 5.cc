#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;

  int ans{}, sum{};
  
  int en = 1;
  for(int st = 1; st <= n; st++){
    while(en <= n && sum < n) sum += en++;
    if(sum == n) ans++;
    sum -= st;
  } 
  
  cout << ans;
}