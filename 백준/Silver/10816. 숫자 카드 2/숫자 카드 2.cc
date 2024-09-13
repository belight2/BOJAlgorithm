// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input
  cin >> n;
  a.resize(n);
  for(auto &x : a) cin >> x;


  // init
  sort(a.begin(), a.end());

  // solve & output
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << upper_bound(a.begin(), a.end(), t) - lower_bound(a.begin(), a.end(), t) << ' ';
  }
}