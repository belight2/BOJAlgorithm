#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
unordered_map<string, int> List;
int k, l;
bool cmp(pair<string, int> &a, pair<string,int> &b){
    return a.Y < b.Y;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string name;
  cin >> k >> l;
  for(int i = 1; i <= l; i++){
    cin >> name;
    List[name] = i;
  }
  vector<pair<string,int>> res(List.begin(), List.end());
  sort(res.begin(), res.end(), cmp);
  k = min(k, (int)res.size());
  for(int i = 0; i < k; i++){
    cout << res[i].first << '\n';
  }
}