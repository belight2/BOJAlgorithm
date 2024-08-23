#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> p(205, -1);

int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] == p[y]) p[x]--;
  if(p[x] < p[y]) p[y] = x;
  else p[x] = y;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;

  for(int cur = 1; cur <= n; cur++){
    for(int nxt = 1; nxt <= n; nxt++){
      int isroad;
      cin >> isroad;
      if(isroad) merge(cur, nxt);
    }
  }
  
  string ans = "YES";
  int cur, par;
  m--;
  cin >> cur;
  par = find(cur);
  while(m--){
    cin >> cur;
    if(par != find(cur)) ans = "NO";
  }
  
  cout << ans;
}