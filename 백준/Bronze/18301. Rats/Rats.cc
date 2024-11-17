// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

double a, b, c;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> a >> b >> c;

  cout << long(floor((a+1) * (b+1) / (c+1) - 1.0));
}