#include <bits/stdc++.h>

using namespace std;

int n;
string number;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> number;
  cout << accumulate(number.begin(), number.end(), 0) - '0' * n;
}