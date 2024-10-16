// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  라운드마다 주어지는 두 점의 번호를 merge하여 같은 집합에 속하게 합니다.

  이미 같은 집합 속한 두 점에 선분을 긋는다면 사이클이 생겼다고 판단할 수 있습니다.
*/
using namespace std;

int n, m;
vector<int> p(500'005, -1);

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  if(p[x] == p[y]) p[x]--;
  if(p[x] > p[y]) swap(x, y);
  p[y] = x;
  return 1;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;

  // solve
  int ans = 0;
  for(int round = 1; round <= m; round++){
    int u, v;
    cin >> u >> v;
    if(!merge(u, v)){
      ans = round;
      break;
    }
  }

  // output
  cout << ans;
}