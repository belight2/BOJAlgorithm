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
vi ans, f;
int oa[256], sa[256], cnt[64];
string a, w, s;
vi failure(const string &s){
  vi f(sz(s));
  int j{};
  for(int i = 1; i < sz(s); i++){
    while(j > 0 && s[i] != s[j]) j = f[j-1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

int kmp(const string &s, const string &p){
  int ret{}, j{};
  for(int i = 0; i < sz(s); i++){
    while(j > 0 && oa[s[i]] != sa[p[j]]) j = f[j-1];
    if(oa[s[i]] == sa[p[j]]) j++;
    if(j == sz(p)){
      j = f[j-1];
      ret++;
    }
  }
  return ret;
}
void solve(){
  vi ().swap(f);
  vi ().swap(ans);
  memset(cnt, 0, sizeof(cnt));

  cin >> a >> w >> s;
  for(int i = 0; i < sz(a); i++) oa[a[i]] = i;
  
  f = failure(w);
  for(int i = 0; i < sz(a); i++){
    for(int j = 0; j < sz(a); j++) sa[a[j]] = (oa[a[j]] + i) % sz(a);
    cnt[i] = kmp(s, w);
  }

  for(int i = 0; i < sz(a); i++) if(cnt[i] == 1) ans.pb(i);

  if(sz(ans) == 0) cout << "no solution\n";
  else if(sz(ans) == 1) cout << "unique: " << ans[0] << nl;
  else{
    cout << "ambiguous: ";
    for(auto &cur : ans) cout << cur << " ";
    cout << nl;
  }
}
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}