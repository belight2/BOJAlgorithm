#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
int n, l;
pi a[10005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l;
  for(int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y;
  sort(a, a+n);
  int tx = a[0].X-1;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(tx >= a[i].Y) continue;
    int cx = tx < a[i].X ? a[i].X : tx+1;
    int len = a[i].Y  - cx;
    int q = len / l;
    if(len%l) q++;
    ans += q;
    tx = cx + q * l - 1;
  }
  cout << ans;
}