#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi = pair<int,int>;
#define X first
#define Y second

int chk(int ps, int cs){
  if((!ps)&&cs) return 1;
  if(ps&&(!cs)) return -1;
  return 0;
}
int n, m;
vector<pi> pos;
vector<ll> cost;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  cin >> n >> m;
  
  cost.resize(n+1);
  for(int i = 1; i <= n; i++) cin >> cost[i];

  sort(cost.begin(), cost.end());
  partial_sum(cost.begin(), cost.end(), cost.begin());

  while(m--){
    int x, y;
    cin >> x >> y;
    pos.push_back({x, 0});
    pos.push_back({y, 1});
  }

  sort(pos.begin(), pos.end());
  
  long long mn{}, mx{};
  int cnt = 1;
  for(int i = 1; i < pos.size(); i++){
    auto &[px, pstate] = pos[i-1];
    auto &[cx, cstate] = pos[i];
    ll diff = cx - px + chk(pstate, cstate);
    mx += (cost[n] - cost[n-cnt]) * diff;
    mn += cost[cnt] * diff;
    (cstate) ? cnt-- : cnt++;
  }
  cout << mn << ' ' << mx;
}