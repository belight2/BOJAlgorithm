#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;  

  vector<int> a(n+1);

  for(int i = 1; i <= n; i++) cin >> a[i];

  partial_sum(a.begin(), a.end(), a.begin());

  while(m--){
    int st, en;
    cin >> st >> en;
    cout << a[en] - a[st-1] << '\n';
  }
}