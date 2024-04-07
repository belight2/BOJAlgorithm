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
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a{}, b{}, s{};
  for(int i = 0; i < 8; i++){
    cin >> s;
    i < 4 ? a += s : b += s;
  }
//#define DEBUG_
#ifndef DEBUG_
  cout << max(a, b);
#endif
#ifdef DEBUG_
#endif
}