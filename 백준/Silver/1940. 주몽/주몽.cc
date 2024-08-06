#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;

  vector<int> a(n);
  for(auto &num : a) cin >> num;

  sort(a.begin(), a.end());

  int ans{};
  int en = n-1;
  for(int st = 0; ; st++){
    while(en > st && a[st]+a[en] > m) en--;
    if(en <= st) break;
    if(a[st]+a[en] == m) ans++;
  }

  cout << ans;
}