#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#define X first
#define Y second
using namespace std;
const char nl = '\n';

int t;
int n;
void solve(){
  unordered_map<string, int> map;
  cin >> n;
  string name, wear;
  for(int i = 0; i < n; i++){
    cin >> name >> wear;
    if(map.find(wear) != map.end()) map[wear]++;
    else map[wear] = 2;
  }
  long long res = 1;
  for(auto e : map){
    res *= e.Y;
  }
  cout << res - 1 << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--) solve();
}