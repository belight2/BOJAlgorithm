#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;
#define X first
#define Y second

vector<int> p(100'005, -1);
vector<pl> cnt(100'005);
ll ans;

int find(int x){
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v) return;
  if(p[u] == p[v]) p[u]--;
  if(p[u] > p[v]) swap(u, v);
  // u가 항상 rank가 큼
  ans -= cnt[u].X * cnt[u].Y + cnt[v].X * cnt[v].Y;
  cnt[u].X += cnt[v].X;
  cnt[u].Y += cnt[v].Y;
  ans += cnt[u].X * cnt[u].Y;
  p[v] = u;
}

int n, m;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++){
    int gender;
    cin >> gender;
    (gender%2) ? cnt[i].X++ : cnt[i].Y++;
  }

  while(m--){
    int u, v;
    cin >> u >> v;
    merge(u, v);
    cout << ans << '\n';
  }
}