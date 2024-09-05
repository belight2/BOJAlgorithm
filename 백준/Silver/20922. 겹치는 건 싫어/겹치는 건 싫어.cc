#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
int chk[100005];
int n, k;

const char nl = '\n';
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  int en = 0;
  int ans = 0;
  for(int st = 0; st < n; st++){
    while(en < n && chk[a[en]]+1 <= k) chk[a[en++]]++;
    ans = max(ans, en - st);
    chk[a[st]]--;
  }
  cout << ans;
}