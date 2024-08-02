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
namespace trie{
  const int root = 1;
  const int mx = 1'000'005;
  int unused = 2;
  int chk[mx];
  int nxt[mx][26];
  void init(){ memset(nxt, -1, sizeof(nxt)); }
  int ctoi(char c){ return c - 'a'; }
  string insert(string &s){
    bool flag{};
    string ret{};
    auto cur = root;
    for(auto c : s){
      if(nxt[cur][ctoi(c)] == -1){
        nxt[cur][ctoi(c)] = unused++;
        if(!flag) ret.pb(c);
        flag = 1;
      }
      if(!flag) ret.pb(c);
      cur = nxt[cur][ctoi(c)];
    }
    chk[cur]++;
    if(!flag && chk[cur] != 1) ret += to_string(chk[cur]);
    return ret;
  }
}
int n;
string str;
int main() {
  fastio(nullptr, false);
  trie::init();
  cin >> n;
  while(n--){
    cin >> str;
    cout << trie::insert(str) << nl;
  }
}