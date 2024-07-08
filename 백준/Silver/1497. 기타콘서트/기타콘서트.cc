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
int n, m;
ll state[10];
int bit_cnt(ll bit, int sz){
  int ret{};
  for(int i = 0; i < sz; i++) if((bit >> i) & 1) ret++;
  return ret;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    string name, tmp;
    cin >> name >> tmp;
    for(int j = 0; j < m; j++){
      state[i] = (state[i] << 1) | (tmp[j] == 'Y');
    }
  }
  pi ans{0, -1};
  for(int i = 0; i < (1 << n); i++){
    ll cur_bit{};
    for(int j = 0; j < n; j++) if(i & (1LL << j))
      cur_bit |= state[j];
    pi cur{bit_cnt(cur_bit, m), bit_cnt(i, n)};
    if(ans.X < cur.X) ans = cur;
    if(ans.X == cur.X && ans.Y > cur.Y) ans.Y = cur.Y;
  }
  cout << ans.Y;
}