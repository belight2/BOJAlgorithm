#include <iostream>
#include <set>
using namespace std;
const char nl = '\n';
void solve(){
  multiset<int> ms;
  char cmd; int x;
  int count; cin >> count;
  while(count--){
    cin >> cmd >> x;
    if(cmd == 'I') ms.insert(x);
    else if(!ms.empty()){
      if(x == 1) ms.erase(--ms.end());
      else ms.erase(ms.begin());
    }
  }
  if(ms.empty()) cout << "EMPTY" << nl;
  else cout << *(--ms.end()) << ' ' << *ms.begin() << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
}