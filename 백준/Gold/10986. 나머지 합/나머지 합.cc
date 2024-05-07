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
int n;
ll ans, m;
vl a(1'000'000);
vl freq(1000);
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
//#define DEBUG_
#ifndef DEBUG_
  ll prefix = 0;
  for(int i = 1; i <= n; i++){
    prefix = (prefix + a[i-1]) % m;
    if(!prefix) ans++;
    freq[prefix]++;
  }
  for(int i = 0; i < m; i++){
    if(!freq[i]) continue;
    ans += (freq[i] * (freq[i] - 1)) / 2;
  }
  cout << ans;
#endif
#ifdef DEBUG_
#endif
}