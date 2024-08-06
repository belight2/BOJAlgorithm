#include <bits/stdc++.h>

using namespace std;

int n, m, a;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;

  vector<int> prefix_sum(n+1);

  for(int i = 1; i <= n; i++){
    cin >> a;
    prefix_sum[i] = prefix_sum[i-1] + a;
  }

  while(m--){
    int sx, ex;
    cin >> sx >> ex;
    cout << prefix_sum[ex] - prefix_sum[sx - 1] << '\n';
  }
}