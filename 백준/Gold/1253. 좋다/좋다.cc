#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  vector<ll> a(n);

  for(auto &num : a) cin >> num;

  sort(a.begin(), a.end());

  int ans{};

  for(int i = 0; i < n; i++){
    ll m = a[i];
    bool is_good_num{};

    int en = n-1;
    for(int st = 0; ; st++){
      while(st < en && (en == i || a[st] + a[en] > m)) en--;
      if(st >= en) break;
      if(a[st]+a[en] == m && st != i) is_good_num = 1;
    }
    if(is_good_num) ans++;
  }
  cout << ans;
}