#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n;
  a.resize(n);
  for(auto &cur : a) cin >> cur;

  int tot = accumulate(a.begin(), a.end(), 0);
  int mx = *max_element(a.begin(), a.end());
  
  cout << double(tot * 100.0 / mx / n);
}