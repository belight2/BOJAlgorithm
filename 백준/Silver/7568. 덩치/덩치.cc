#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pi;
const char nl = '\n';
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<pi> a(n);
  for(auto &val : a) cin >> val.X >> val.Y;
  for(int i = 0; i < n; i++){
    int rank = 1;
    pi cur = a[i];
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      if(cur.X < a[j].X && cur.Y < a[j].Y) rank++;
    }
    cout << rank << ' ';
  }
}