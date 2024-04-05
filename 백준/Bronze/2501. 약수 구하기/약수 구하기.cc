#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//#define _DEBUG_
using namespace std;
const char nl = '\n';
int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<int> a;
  for(int i = 2; i * i <= n; i++){
    if(!(n%i)){
      a.pb(i);
      if(n/i != i) a.pb(n/i);
    }
  }
  a.pb(1); a.pb(n);
  sort(all(a));
#ifndef _DEBUG_
  a.size() < k ? cout << 0 : cout << a[k-1];
#endif
#ifdef _DEBUG_
  cout << a.size() << nl;
  for(auto x : a) cout << x << ' ';
#endif
}