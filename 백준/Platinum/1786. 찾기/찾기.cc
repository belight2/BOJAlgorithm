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
vi pos;
vi failure(const string &s){
  vi f(sz(s));
  int j{};
  for(int i = 1; i < sz(s); i++){
    while(j > 0 && s[i] != s[j]) j = f[j-1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
void kmp(const string &s, const string &p){
  vi f = failure(p);
  int j{};
  for(int i = 0; i < sz(s); i++){
    while(j > 0 && s[i] != p[j]) j = f[j-1];
    if(s[i] == p[j]) j++;
    if(j == sz(p)){
      pos.pb(i-j+2);
      j = f[j-1];
    }
  }
}
int main() {
  fastio(nullptr, false);
  string t, p;
  getline(cin, t);
  getline(cin, p);
  kmp(t, p);
  cout << sz(pos) << nl;
  for(int &cur : pos) cout << cur << ' ';
}