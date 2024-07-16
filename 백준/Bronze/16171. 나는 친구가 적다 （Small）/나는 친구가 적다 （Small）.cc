#include <bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(nullptr) -> sync_with_stdio(false);
  string s{}, k{}, a{};
  cin >> s >> k;
  for(auto it = s.begin(); it < s.end(); it++){
    if(isalpha(*it)) a.push_back(*it);
  } 
  
  int len = k.size();
  bool ans{};
  for(auto it = a.begin(); it < a.end() - len + 1; it++){
    if(ans = (string(it, it+len) == k), ans) break;
  }
  cout << ans;
}