#include <bits/stdc++.h>

using namespace std;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;

  cin >> n;

  vector<int> a(n);
  for(auto &x : a) cin >> x;

  // bubble sort
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(a[j] > a[j+1]) 
        swap(a[j], a[j+1]);
    }
  }

  for(auto &x : a) cout << x << '\n';
}