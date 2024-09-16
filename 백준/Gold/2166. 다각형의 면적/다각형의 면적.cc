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

using pdd = pair<double, double>;
using vpd = vector<pdd>;

int n;
vpd pos;

double CCW(pdd &a, pdd &b, pdd &c){
  return (a.X * b.Y + b.X * c.Y + c.X * a.Y) - (c.X * b.Y + b.X * a.Y + a.X * c.Y);
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  vpd (n).swap(pos);
  for(auto &[x, y] : pos) cin >> x >> y;

  // solve
  double ans{};
  for(int i = 1; i < n-1; i++){
    ans += CCW(pos[i], pos[0], pos[i+1]);
  }
  ans = abs(ans / 2.);

  // output
  cout << fixed << setprecision(1) << ans; 
}