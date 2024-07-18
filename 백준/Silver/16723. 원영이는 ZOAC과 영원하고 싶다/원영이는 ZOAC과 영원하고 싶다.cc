#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  ll ret{};
  for(int i = 0; (1 << i) <= n; i++){
    int a = (n+(1<<i)), b = (1 << (i+1));
    ret +=  a / b * b;
  }
  cout << ret;
}