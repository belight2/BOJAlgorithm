#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull GCD(ull a, ull b){ return (b ? GCD(b, a%b) : a); }

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  ull a, b;
  cin >> a >> b;
  int ans = GCD(a, b);
  while(ans--) cout << 1;
}