// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
int a[10'005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  // solve
  long long ans{};
  sort(a, a+n);
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      int x = a[i] + a[j];
      /*
        두 명은 먼저 선택한 다음에
        나머지 한 명은 이분 탐색으로 찾되, 여러 명 있는 경우를 고려해
        upper_bound와 lower_bound를 사용해 구한다.
      */
      ans += upper_bound(a+j+1, a+n, -x) - lower_bound(a+j+1, a+n, -x);
    }
  }

  // output
  cout << ans;
}