#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, m;

  cin >> n;
  vector<int> a(n);
  for(auto &x : a) cin >> x;
  
  sort(a.begin(), a.end());

  cin >> m;
  while(m--){
    int x;
    cin >> x;
    cout << binary_search(a.begin(), a.end(), x) << '\n';
  }
}