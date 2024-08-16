#include <bits/stdc++.h>

using namespace std;

const char nl = '\n';

int n, m;
vector<int> lec;

bool solve(int th){
  int cnt = 1, tot{}, mx{};
  for(int i = 0; i < n; i++){
    if(tot + lec[i] > th){
      mx = max(mx, tot);
      cnt++;
      tot = 0;
    }
    tot += lec[i];
  }
  mx = max(mx, tot);
  return cnt <= m && mx <= th;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;
  lec.resize(n);
  for(auto &cur : lec) cin >> cur;

  int st = 0;
  int en = 1e9+1;
  while(st < en){
    int mid = (st+en)/2;
    if(solve(mid)) en = mid;
    else st = mid+1;
  }
  cout << st;
}