#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
const char nl = '\n';
int x, y, d, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y >> d >> t;
  d = max(d, t);
  double z = sqrt(x*x+y*y);
  int q = z / d;
  double ans = min({max(q + 1, 2) * t * 1.0, q * (t - d) + z, (q + 1) * (t + d) - z});
  cout << fixed;
  cout.precision(10);
  cout << ans;
}