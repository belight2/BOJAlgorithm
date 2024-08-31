#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int a[2];
int d[500'005], c[500'005]; // Decrease, inCrease

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> a[0];
  
  d[1] = c[1] = 1;
  for(int i = 2; i <= n; i++){
    cin >> a[1];
    d[i] = (a[0] >= a[1] ? d[i-1] : i);
    c[i] = (a[0] <= a[1] ? c[i-1] : i);
    swap(a[0], a[1]);
  }

  ll ans = 1;
  for(int i = 2; i <= n; i++){
    ans +=  i + 1 - (d[i] != i ? c[d[i]] : c[i]);
  }
  cout << ans;
}