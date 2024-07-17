#include <iostream>
#include <deque>
#include <utility>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> P;
const char nl = '\n';
int n, l, a;
deque<P> dq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l;
  for(int i = 1; i <= n; i++){
    cin >> a;
    while(!dq.empty() && i == dq.front().Y + l) dq.pop_front();
    while(!dq.empty() && dq.back().X > a) dq.pop_back();
    dq.push_back({a, i});
    cout << dq.front().X << ' ';
  }
}