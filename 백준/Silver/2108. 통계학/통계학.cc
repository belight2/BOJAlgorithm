#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
const char nl = '\n';
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> b(8001);
  for(int x : a) b[x+4000]++;
  auto it1 = max_element(b.begin(), b.end());
  auto it2 = find(it1+1, b.end(), *it1);
  int avg = lround((accumulate(a.begin(), a.end(), 0)*1.0)/n);
  int mode = ( it2 == b.end() ? it1 : it2 ) - b.begin() - 4000;
  cout << avg << nl << a[n/2] << nl << mode << nl << a[n-1] - a[0];
}