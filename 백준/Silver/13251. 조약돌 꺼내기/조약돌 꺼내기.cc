// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int m, k;
int a[55];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> m;
  for(int i = 0; i < m; i++) cin >> a[i];
  cin >> k;

  long tot = accumulate(a, a + m, 0);
  
  double ans = 0.0;
  for(int i = 0; i < m; i++){
    if(a[i] < k) continue;
    double cur = 1.0;
    for(int j = 0; j < k; j++){
      cur *= (double)(a[i] - j) / (tot - j);
    }
    ans += cur;
  }

  cout << fixed;
  cout.precision(9);
  cout << ans;
}