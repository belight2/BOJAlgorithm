#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
const char nl = '\n';
int n;
vector<int> a;
ll d[105][25];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  d[0][a[0]] = 1;
  for(int i = 1; i < n-1; i++){
    for(int j = 0; j <= 20; j++){
      if(!d[i-1][j]) continue;
      if(j+a[i] <= 20) d[i][j+a[i]] += d[i-1][j];
      if(0 <= j-a[i]) d[i][j-a[i]] += d[i-1][j]; 
    }
  }
  cout << d[n-2][a[n-1]];
}