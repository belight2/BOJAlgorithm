#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef vector<char> vc;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vs str(n);
  for(int i = 0; i < n; i++) cin >> str[i];
  vl p(10);
  vb nonz(10); // 0이 될 수 없는 문자
  for(auto cur : str){
    nonz[cur[0]-'A'] = 1;
    reverse(all(cur));
    ll pos = 1;
    for(char c : cur){
      p[c-'A'] += pos;
      pos *= 10;
    }
  }
  bool flag = 0;
  for(int i = 0; i < 10; i++) if(!p[i]) flag = 1;
  if(!flag){
    ll mn = 1e15;
    int idx;
    for(int j = 0; j < 10; j++){
      if(!nonz[j] && mn > p[j]){
        mn = p[j];
        idx = j;
      }
    }
    p[idx] = 0;
  }
  sort(all(p));
  ll ans{};
  for(int i = 0; i < 10; i++) ans += i * p[i];
  cout << ans;
}