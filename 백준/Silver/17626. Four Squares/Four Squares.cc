#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
const char nl = '\n';
int n;
int d[50005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    d[i] = d[i-1] + 1;
    for(int j = 1; j * j <= i; j++){
      d[i] = min(d[i], d[i- j*j] + 1);
    }
  }
//#define DEBUG_
#ifndef DEBUG_
  cout << d[n];
#endif
#ifdef DEBUG_
#endif
}