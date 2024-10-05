// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;

void hanoi(int a, int b, int c, int n){
  if(n == 1){
    cout << a << ' ' << c << '\n';
    return;
  }
  hanoi(a, c, b, n-1);
  cout << a << ' ' << c << '\n';
  hanoi(b, a, c, n-1);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;

  // output
  // 시간복잡도가 몇 인지 알고 있다면 메모리 사용량을 줄일 수 있음.
  cout << (1 << n) - 1 << '\n';
  hanoi(1, 2, 3, n);

}