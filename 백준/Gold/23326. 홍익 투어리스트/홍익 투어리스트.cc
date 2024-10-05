#include <iostream>
#include <set>
using namespace std;
const char nl = '\n';
int n, q;
int op, x;
bool area[500'001];
set<int> att;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> area[i];
    if(area[i]) att.insert(i);
  }
  int cur = 0;
  while(q--){
    cin >> op;
    if(op == 1){
      cin >> x;
      x--;
      if(area[x]){
        area[x] = 0;
        att.erase(x);
      }
      else{
        area[x] = 1;
        att.insert(x);
      }
    }
    else if(op == 2){
      cin >> x;
      cur = (cur + x) % n;
    }
    else{
      auto curTo = att.lower_bound(cur);
      auto beginTo = att.lower_bound(0);
      if(curTo != att.end()){
        cout << *curTo - cur << nl;
      }
      else if(beginTo == att.end()){
        cout << -1 << nl;
      }
      else{
        cout << (n - cur) + *beginTo << nl;
      }
    }
  }
}