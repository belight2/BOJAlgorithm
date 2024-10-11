// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[10];
int a[10];

void solve(int k){
  if(k == m){
    for(int i = 0; i < m; i++) cout << a[i] << ' ';
    cout << '\n';
    return;
  }
  
  for(int i = 0; i < n; i++){
    a[k] = num[i];
    solve(k+1);
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];

  // solve
  sort(num, num+n);
  solve(0);
}