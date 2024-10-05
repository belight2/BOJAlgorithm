#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int n, m;
unordered_map<string, string> map;
const char nl = '\n';
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string site, password;
  cin >> n >> m;
  while(n--){
    cin >> site >> password;
    map[site] = password;
  } 
  while(m--){
    cin >> site;
    cout << map[site] << nl;
  }
}