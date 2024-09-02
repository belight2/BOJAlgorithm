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
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const char nl = '\n';
const int INF = 1e9;

ll A(ll cur) { return cur*2; }
ll B(ll cur) { return cur*10+1; }

ll (*f[])(ll) = { A, B };
unordered_map<ll, ll> vis;

ll a, b;

int main() {
  fastio(nullptr, false);
  
  cin >> a >> b;
  
  ql q;
  vis[a] = 0;
  q.push(a);
  while(q.size()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 2; dir++){
      auto nxt = f[dir](cur);
      if(nxt > INF) continue;
      if(vis.find(nxt) != vis.end() && vis[nxt] <= vis[cur]+1) continue;
      vis[nxt] = vis[cur] + 1;
      q.push(nxt);
    }
  }
  cout << (vis.find(b) == vis.end() ? -1 : vis[b]+1);
}