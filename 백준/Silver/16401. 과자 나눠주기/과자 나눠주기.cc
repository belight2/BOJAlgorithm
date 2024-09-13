// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> cookie;

bool solve(int x){
  int cur{};
  for(int i = 0; i < n; i++) cur += cookie[i] / x;
  return cur >= m;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> m >> n;
  cookie.resize(n);
  for(auto &a : cookie) cin >> a;

  // solve
  sort(cookie.begin(), cookie.end());
  int st = 1, en = 1e9;
  while(st < en){
    int mid = (st+en+1)>>1; // 오른쪽으로 1칸 쉬프트 이동을 하면 /2를 한 것과 똑같음 ex) (4 >> 1) == 2 임
    (solve(mid)) ? st = mid : en = mid-1; 
  }

  // output
  cout << (solve(st) ? st : 0);
}