#include <iostream>
using namespace std;
const char nl = '\n';
bool ispos(int n){
  int seq = 0;
  int r;
  while(n != 0){
    r = n % 10;
    n = n / 10;
    if(r == 6) seq++;
    else seq = 0;
    if(seq == 3) return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int idx = 1;
  int init = 666;
  while( idx < n){
    if(ispos(++init)) idx++;
  }
  cout << init;
}