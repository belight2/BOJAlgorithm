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
int h[3];
int j[2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 3; i++) cin >> h[i];
  for(int i = 0; i < 2; i++) cin >> j[i];
  int mn = 1e9+10;
  for(int i = 0; i < 3; i++){
    for(int k = 0; k < 2; k++){
      mn = min(mn, h[i]+j[k]-50);
    }
  }
//#define DEBUG_
#ifndef DEBUG_
  cout << mn;
#endif
#ifdef DEBUG_
#endif
}