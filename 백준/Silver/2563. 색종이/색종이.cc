#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
const char nl = '\n';
int a[105][105];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n{}, x{}, y{};
  cin >> n;
  while(n--){
    cin >> x >> y;
    for(int i = x; i < x+10; i++){
      for(int j = 90 - y; j < 100-y; j++){
        a[i][j] = 1;
      }
    }
  }
  int ans = count(&a[0][0], &a[99][100], 1);
  cout << ans;
}