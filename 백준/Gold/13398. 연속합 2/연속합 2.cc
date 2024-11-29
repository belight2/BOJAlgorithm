// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
int a[100'005];
int d[2][100'005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  d[0][0] = d[1][0] = a[0];
  for(int i = 1; i < n; i++){
    d[0][i] = max(d[0][i-1] + a[i], a[i]);
    d[1][i] = max(d[0][i-1], d[1][i-1] + a[i]);
  }

  cout << max(*max_element(d[0], d[0] + n), *max_element(d[1], d[1] + n));
}