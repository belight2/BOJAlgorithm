// Authored by : chjh2129
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
vector<int> x, y;
ll a[4005], b[4005], c[4005], d[4005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

  // init
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      x.push_back(a[i]+b[j]);
      y.push_back(c[i]+d[j]);
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  // solve
  ll ans{};
  for(int val : x){
    ans += upper_bound(y.begin(), y.end(), -val) - lower_bound(y.begin(), y.end(), -val);
  }

  // output
  cout << ans;
}