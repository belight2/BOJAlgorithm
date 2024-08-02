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
int n;
string str;
namespace trie{
  const int root = 1;
  const int mx = 100'005;
  int unused = 2;
  bool chk[mx];
  int nxt[mx][10];
  
  void init(){
    unused = 2;
    memset(chk, 0, sizeof(chk));
    memset(nxt, -1, sizeof(nxt));
  }
  int ctoi(char c){ return c - '0'; }

  bool insert(string &s){
    int cur = root;
    for(auto c : s){
      if(nxt[cur][ctoi(c)] == -1) nxt[cur][ctoi(c)] = unused++;
      cur = nxt[cur][ctoi(c)];
      if(chk[cur]) return 0;
    }
    if(cur != unused - 1) return 0;
    chk[cur] = 1;
    return 1;
  }
}
void solve(){
  trie::init();
  string ans = "YES";
  cin >> n;
  while(n--){
    cin >> str;
    if(!trie::insert(str)) ans = "NO";
  }
  cout << ans << nl;
}
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}