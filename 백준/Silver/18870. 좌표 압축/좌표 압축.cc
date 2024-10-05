// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> x, pos;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  x.resize(n);
  pos.resize(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
    pos[i] = x[i];
  }

  // solve
  sort(pos.begin(), pos.end());
  // 배열 내 중복을 제거하는 방법 O(N)
  pos.erase(unique(pos.begin(), pos.end()), pos.end());
  
  // output
  for(auto &a : x){
    cout << lower_bound(pos.begin(), pos.end(), a) - pos.begin() << ' ';
  }
}