#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const char nl = '\n';
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  if(n == 0){
    cout << 0;
    return 0;
  }
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int t = lround((n*1.0)*0.15);
  auto l = a.begin();
  auto r = a.end();
  n -= t + t;
  while(t--){
    l++; r--;
  }
  cout << lround(accumulate(l, r, 0)*1.0/n);
}