#include <bits/stdc++.h>

using namespace std;

int n, m, q, u, v;
vector<int> p(1'000'005, -1);

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

  while(m--){
    cin >> q >> u >> v;
    if(!q) merge(u, v);
    else if(find(u) == find(v)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}