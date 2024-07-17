#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
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
const string INF = string(8, 'Z');
const char rsp[] = { 'P', 'R', 'S' };
int n, a[3];
string ans, cur;
char get_winner(char a, char b){
  if(a > b) swap(a, b);
  if(a == 'P' && b == 'S') return 'S';
  return min(a, b);
}
bool is_draw(int round, string cur){
  if(round == 1) return 1;
  string nxt{};
  for(int i = 0; i < round; i+=2){
    if(cur[i] == cur[i+1]) return 0;
    nxt.pb(get_winner(cur[i], cur[i+1]));
  }
  return is_draw(round/2, nxt);
}
void func(){
  if(ans != INF) return;
  if(!a[0] && !a[1] && !a[2]){
    if(is_draw((1<<n), cur)) ans = cur;
    return;
  }
  for(int i = 0; i < 3; i++){
    if(a[i] > 0){
      a[i]--;
      cur.pb(rsp[i]);
      func();
      a[i]++;
      cur.pop_back();
    }
  }
}
void solve(){
  cin >> n;
  cin >> a[1] >> a[0] >> a[2];
  ans = INF;
  func();
  if(ans == INF) ans = "IMPOSSIBLE";
  cout << ans << nl;
}
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }
}