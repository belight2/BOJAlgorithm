#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

int CCW(pl a, pl b, pl c){
  ll ret = (a.X * b.Y + b.X * c.Y + c.X * a.Y) - (a.X * c.Y + c.X * b.Y + b.X * a.Y);
  if(ret == 0) return 0;
  return (ret > 0) ? 1 : -1;
}

bool isinner(pl a, pl b, pl c){
  return min(a.X, b.X) <= c.X && c.X <= max(a.X, b.X) && min(a.Y, b.Y) <= c.Y && c.Y <= max(a.Y, b.Y);
}

int main() {
  fastio(nullptr, false);
  pl p[4];
  for(int i = 0; i < 4; i++) cin >> p[i].X >> p[i].Y;
  
  bool flag{};
  vi ccw;
  for(int i = 0; i < 4; i++){
    pl &a = p[(i&2)], &b = p[(i&2)|1], &c = p[(i^2)];
    ccw.pb(CCW(a, b, c));
    if(ccw[i] == 0 && isinner(a, b, c)){
      flag = 1;
      break;
    }
  }
  cout << (flag ? flag : ((ccw[0]*ccw[1]) < 0 && (ccw[2] * ccw[3]) < 0 ));
}