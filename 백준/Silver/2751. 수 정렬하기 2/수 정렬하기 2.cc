#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n{};
  cin >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  for(auto &x : a) cout << x << "\n";
}