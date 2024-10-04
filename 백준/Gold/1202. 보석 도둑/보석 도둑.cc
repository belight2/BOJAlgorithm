#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
int n, k, m, v, c;
vector<pair<int,int>> jew;
multiset<int> bag;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  while(n--){
    cin >> m >> v;
    jew.push_back({v, m});
  }
  while(k--){
    cin >> c; bag.insert(c);
  }
  sort(jew.rbegin(), jew.rend());
  long long ans = 0;
  for(auto x : jew){
    if(bag.empty()) break;
    v = x.X; m = x.Y;
    auto it = bag.lower_bound(m);
    if(it == bag.end()) continue;
    ans += v;
    bag.erase(it);
  }
  cout << ans;
}