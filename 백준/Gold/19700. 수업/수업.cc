#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <tuple>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
int N, h, k;
multiset<int> team;
pair<int,int> stu[500'001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> stu[i].X >> stu[i].Y;
  }
  sort(stu, stu+N, greater<pair<int,int>>());
  team.insert(1);
  for(int i = 1; i < N; i++){
    tie(h, k) = stu[i];
    auto it = team.lower_bound(k);
    if(it == team.begin()){
      team.insert(1);
      continue;
    }
    it = prev(it);
    int tmp = *it + 1;
    team.erase(it);
    team.insert(tmp);
  }
  cout << team.size();
}