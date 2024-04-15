#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sec{}, a{};
  for(int i = 0; i < 4; i++){
    cin >> a;
    sec += a;
  }
//#define DEBUG_
#ifndef DEBUG_
  cout << sec/60 << nl << sec%60;
#endif
#ifdef DEBUG_
#endif
}