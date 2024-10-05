#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const char nl = '\n';
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  unordered_set<string> set;
  int n;
  cin >> n;
  string name, state;
  while(n--){
    cin >> name >> state;
    if(state == "enter") set.insert(name);
    else set.erase(name);
  }
  vector<string> v;
  for(auto e : set) v.push_back(e);
  sort(v.rbegin(), v.rend());
  for(auto res : v) cout << res << nl;
}