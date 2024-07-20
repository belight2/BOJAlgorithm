#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n;
pi a[55];
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y;
  sort(a, a+n);
  int mx_cost{};
  int ans{};
  for(int i = 0; i < n; i++){
    int cost = a[i].X;
    int cur{};
    for(int j = 0; j < n; j++){
      if(cost > a[j].X) continue;
      if(cost - a[j].Y > 0) cur += cost - a[j].Y;
    }
    if(mx_cost < cur){
      mx_cost = cur;
      ans = cost;
    }
  }
  cout << ans;
}