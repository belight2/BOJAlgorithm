#include <iostream>
#include <string>
using namespace std;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n{};
  string number{};
  cin >> n >> number;
  int ans{};
  for(int i = 0; i < n; i++){
    ans += number[i] - '0';
  }
  cout << ans;
}