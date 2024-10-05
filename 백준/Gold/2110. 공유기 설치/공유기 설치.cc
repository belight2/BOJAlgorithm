// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, c;
int a[200'005];

bool solve(int mid){
  int idx{}, cnt{};
  while(idx != n){
    idx = lower_bound(a+idx, a+n, a[idx]+mid) - a;
    cnt++;
  }
  return cnt >= c;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> c;
  for(int i = 0; i < n; i++) cin >> a[i];

  // solve
  sort(a, a+n);
  int st{}, en = 1e9+1;
  while(st < en){
    int mid = (st+en+1)>>1;
    (solve(mid) ? st = mid : en = mid-1);
  }
  
  // output
  cout << st;
}