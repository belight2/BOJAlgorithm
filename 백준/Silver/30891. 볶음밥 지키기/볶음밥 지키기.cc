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
#define f(x, y) (((x)-(y))*((x)-(y)))
const char nl = '\n';
int n, r;
int main() {
  fastio(nullptr, false);
  cin >> n >> r;
  vpi pos(n);
  for(auto &cur : pos) cin >> cur.X >> cur.Y;
  pi ans{};
  int mx{};
  for(int x = -100; x <= 100; x++){
    for(int y = -100; y <= 100; y++){
      int cnt{};
      for(auto &cur : pos){
        if(f(x, cur.X) + f(y, cur.Y) <= r * r)
          cnt++;
      }
      if(cnt > mx){
        mx = cnt;
        ans = {x, y};
      }
    }
  }
  cout << ans.X << ' ' << ans.Y;
}