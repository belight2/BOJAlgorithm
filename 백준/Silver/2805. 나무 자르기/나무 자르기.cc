// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
int tree[1'000'005];

bool solve(int x){
  ll cur{};
  for(int i = 0; i < n; i++){
    if(tree[i] <= x) continue;
    cur += tree[i] - x;
  }
  return cur >= m;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> tree[i];

  // solve
  int st{}, en = 1e9;
  while(st < en){
    int mid = (st+en+1)>>1;
    (solve(mid) ? st = mid : en = mid-1);
  }

  // output
  cout << st;
}