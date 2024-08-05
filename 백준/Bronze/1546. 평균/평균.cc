#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &cur : a) cin >> cur;
  int tot = accumulate(a.begin(), a.end(), 0);
  int mx = *max_element(a.begin(), a.end());
  double ans = tot * 100.0 / mx / n;
  cout << ans;
}