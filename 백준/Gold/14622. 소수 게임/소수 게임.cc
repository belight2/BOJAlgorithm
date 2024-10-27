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

int n;
vb isprime(5'000'005, 1);
vb vis(5'000'005);

ll dsc, ksc;
priority_queue<int, vi, greater<int>> d, k;

void eratos(){
  isprime[0] = isprime[1] = 0;
  for(int i = 2; i * i <= 5'000'000; i++){
    if(!isprime[i]) continue;
    for(int j = i * i; j <= 5'000'000; j += i) isprime[j] = 0;
  }
}


void solve(int x, ll &src, ll &dst, bool f = 1){
  auto &cur = (f ? d : k);
  auto &nxt = (f ? k : d);
  if(isprime[x]){
    if(vis[x]){
      src -= 1000;
      return;
    }
    vis[x] = 1;
    cur.push(x);
    if(sz(cur) > 3) cur.pop();
    return;
  }  
  dst += (sz(nxt) < 3 ? 1000 : nxt.top());
}

int main() {
  fastio(nullptr, false);
  
  // init
  eratos();

  // input
  cin >> n;
  while(n--){
    int u, v;
    cin >> u >> v;
    solve(u, dsc, ksc);
    solve(v, ksc, dsc, 0);
  }

  if(dsc == ksc) cout << "우열을 가릴 수 없음";
  else if(dsc < ksc) cout << "소수 마스터 갓규성";
  else cout << "소수의 신 갓대웅";
}