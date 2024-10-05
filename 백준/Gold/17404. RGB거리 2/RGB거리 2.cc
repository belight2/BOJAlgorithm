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
const int INF = 0x3f3f3f3f;
int n, a[1005][3], d[2][3];
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++){
    for(auto &x : a[i]) cin >> x;
  }
  int ans = INF;
  for(int st = 0; st < 3; st++){
    fill(d[1], d[1]+3, INF);
    for(int i = 0; i < 3; i++){
      if(i == st) continue;
      d[1][i] = a[0][st] + a[1][i];
    }
    for(int i = 2; i < n; i++){
      memcpy(d[0], d[1], sizeof(d[0]));
      for(int j = 0; j < 3; j++){
        d[1][j] = a[i][j] + min(d[0][(j+1)%3], d[0][(j+2)%3]);
      }
    }
    for(int en = 0; en < 3; en++){
      if(en == st) continue;
      ans = min(ans, d[1][en]);
    }
  }
  cout << ans;
  
}