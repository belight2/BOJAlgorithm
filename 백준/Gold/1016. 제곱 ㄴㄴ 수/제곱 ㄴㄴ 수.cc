#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mn, mx;
vector<bool> chk(1'000'005, 1);

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> mn >> mx; 
  for(ll i = 2; i <= mx / i; i++){
    ll cur = i * i;
    for(ll j = (mn/cur)*cur; j <= mx; j += cur){
      if(j < mn) continue;
      chk[j - mn] = 0;
    }
  }
  int ans{};
  for(int i = 0; i < mx - mn + 1; i++) if(chk[i]) ans++;
  cout << ans;
}