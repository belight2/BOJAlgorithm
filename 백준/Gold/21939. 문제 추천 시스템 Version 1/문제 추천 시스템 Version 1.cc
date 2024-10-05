#include <iostream>
#include <set>
#include <string>
using namespace std;
const char nl = '\n';
string cmd;
int n, m, p, l;
int problem[100'002];
set<int> Level[101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  while(n--){
    cin >> p >> l;
    problem[p] = l;
    Level[l].insert(p);
  }
  cin >> m;
  while(m--){
    cin >> cmd;
    if(cmd == "add"){
      cin >> p >> l;
      problem[p] = l;
      Level[l].insert(p);
    }
    else if(cmd == "solved"){
      cin >> p;
      Level[problem[p]].erase(p);
    }
    else if(cmd == "recommend"){
      cin >> p;
      if(p == 1){
        for(int i = 100; i >= 0; i--){
          if(Level[i].empty()) continue;
          cout << *prev(Level[i].end()) << nl;
          break;
        }
      }
      else{
        for(int i = 0; i <= 100; i++){
          if(Level[i].empty()) continue;
          cout << *Level[i].begin() << nl;
          break;
        }
      }
    }
  }
}