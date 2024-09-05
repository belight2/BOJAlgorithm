#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
vector<bool> chk(100005); 

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  // solve
  int en{};
  long long ans{};
  for(int st = 0; st < n; st++){
    while(en < n && !chk[a[en]]) chk[a[en++]] = 1;
    ans += en - st;
    chk[a[st]] = 0;
  }

  // output
  cout << ans;
}