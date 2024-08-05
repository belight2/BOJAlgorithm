#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n{};
  cin >> n;
  vector<double> a(n);
  for(auto &cur : a) cin >> cur;
  sort(a.rbegin(), a.rend());
  double tot{};
  for(int i = 0; i < n; i++){
    tot += a[i] / a[0] * 100.0;
  }
  cout << tot / double(n);
}