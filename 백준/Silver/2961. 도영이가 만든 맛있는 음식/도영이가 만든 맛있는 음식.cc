#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n;
pl taste[15]; // {신맛, 쓴맛}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> taste[i].X >> taste[i].Y;
  ll ans = 0x3f3f3f3f;
  for(int i = 1; i < (1 << n); i++){
    int cur_bit = i;
    pl cur{1, 0};
    for(int j = 0; j < n; j++) 
      if(cur_bit & (1 << j)){
        cur.X *= taste[j].X;
        cur.Y += taste[j].Y;
      }
    ans = min(ans, abs(cur.X - cur.Y));
  }
  cout << ans;
}