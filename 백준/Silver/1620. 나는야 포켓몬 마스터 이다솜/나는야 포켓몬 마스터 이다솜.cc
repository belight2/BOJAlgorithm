#include <iostream>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;
const char nl = '\n';
unordered_map<string, int> STI;
string ITS[100005];
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> ITS[i];
    STI[ITS[i]] = i;  
  }
  string query;
  while(m--){ 
    cin >> query;
    if(isdigit(query[0])) cout << ITS[stoi(query)] << nl;
    else cout << STI[query] << nl;
  }
}