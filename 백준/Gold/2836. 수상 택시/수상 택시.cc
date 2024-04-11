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
int n, m;
ll solve(vpi &p){
  if(p.empty()) return 0L;
  ll ans{};
  ll st = p[0].X;
  ll en = p[0].Y;
  for(int i = 1; i < p.size(); i++){
    if(p[i].X <= en) en = max(en, static_cast<ll>(p[i].Y));
    else{
      ans += (en - st) * 2;
      st = p[i].X; en = p[i].Y;
    }
  }
  ans += (en - st) * 2;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  ll ans = m;
  vpi pos;
  while(n--){
    int a, b;
    cin >> a >> b;
    if(a < b) continue;
    pos.pb({b, a});
  }
  sort(all(pos));
  ans += solve(pos);
//#define DEBUG_
#ifndef DEBUG_
  cout << ans;
#endif
#ifdef DEBUG_
  for(auto cur : pos) cout << cur.X << ' ' << cur.Y << nl;
#endif
}