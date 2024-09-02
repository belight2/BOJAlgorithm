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
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

const int MOD = 1e4;

int D(int cur){ return (cur*2)%MOD; }
int S(int cur){ return ((cur-1 < 0) ? 9999 : cur-1);}
int R(int cur){ return (cur ? ((cur/10) + (cur%10)*1000) : 0 ); }
int L(int cur){ return (cur ? ((cur%1000)*10 + cur/1000) : 0 ); }

int (*f[])(int cur) = { D, S, R, L };
char convert[4] = {'D', 'S', 'R', 'L'};

bool vis[10000];
int a, b;

void solve(){
  memset(vis, 0, sizeof(vis));
  cin >> a >> b;
  queue<pair<int, string>> q;
  q.push({a, ""});
  while(q.size()){
    auto [cur, cmd] = q.front(); q.pop();
    if(cur == b){
      cout << cmd << nl;
      return;
    }
    for(int dir = 0; dir < 4; dir++){
      int nxt = f[dir](cur);
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      q.push({nxt, cmd+convert[dir]});
    }
  }
}

int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}