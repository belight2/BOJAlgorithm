// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[10];
bool isused[10];
int a[10];

void solve(int k){
  if(k == m){
    for(int i = 0; i < m; i++) cout << a[i] << ' ';
    cout << '\n';
    return;
  }

  int tmp = 0;

  for(int i = 0; i < n; i++){
    if(isused[i] || tmp == num[i]) continue;
    isused[i] = 1;
    a[k] = num[i];
    tmp = a[k];
    solve(k+1);
    isused[i] = 0;
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