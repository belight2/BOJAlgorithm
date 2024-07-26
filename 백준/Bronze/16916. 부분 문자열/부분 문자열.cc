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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
vi failure(string &s){
  vi f(s.size());
  int j{};
  for(int i = 1; i < s.size(); i++){
    while(j < 0 && s[i] != s[j]) j = f[j-1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
bool kmp_search(string &s, string &p){
  vi f = failure(p);
  int j{};
  for(int i = 0; i < s.size(); i++){
    while(j > 0 && s[i] != p[j]) j = f[j-1];
    if(s[i] == p[j]) j++;
    if(j == p.size()) return 1;
  }
  return 0;
}
int main() {
  fastio(nullptr, false);
  string s, p;
  cin >> s >> p;
  cout << kmp_search(s, p);
}