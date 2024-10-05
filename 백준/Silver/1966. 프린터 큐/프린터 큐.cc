#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
void solve(){
  int n, m, imp;
  vector<int> a;
  queue<int> p;
  queue<pair<int,int>> q;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> imp;
    a.push_back(imp);
    q.push({imp, i});
  }
  sort(a.rbegin(), a.rend());
  for(int x : a) p.push(x);
  while(1){
    auto cur = q.front(); q.pop();
    if(cur.X == p.front()){
      if(cur.Y == m){
        cout << n - q.size() << nl;
        return;
      }
      p.pop();
    }
    else q.push(cur);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
}