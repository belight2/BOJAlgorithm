// authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7fffffff;
int n, s;
int a[100'005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> s;
  for(int i = 0; i < n; i++) cin >> a[i];

  // solve
  int ans = INF;
  int tot{}, en{};
  for(int st = 0; st < n; st++){
    while(en < n && tot < s) tot += a[en++];
    if(tot >= s) ans = min(ans, en - st);
    tot -= a[st];
  }

  // output
  cout << (ans == INF ? 0 : ans);
}