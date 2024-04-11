#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define mod 1'000'000'000
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vl d(n+1);
  d[1] = 0;
  d[2] = 1;
  for(int i = 3; i <= n; i++){
    d[i] = (i-1) * (d[i-1] + d[i-2]) % mod;
  }
//#define DEBUG_
#ifndef DEBUG_
  cout << d[n];
#endif
#ifdef DEBUG_
#endif
}