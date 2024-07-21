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
int n, a[1005], d[1005], path[1005];
int solve(int cur){
  if(d[cur] != 1) return d[cur];
  if(cur == 0) return 1;
  for(int j = cur-1; j >= 0; j--){
    if(a[cur] > a[j]){
      int len = 1 + solve(j);
      if(d[cur] < len){
        d[cur] = len;
        path[cur] = j;
      }
    }
  }
  return d[cur];
}
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  fill(d, d+n, 1);
  fill(path, path+n, -1);
  
  for(int i = n-1; i > 0; i--){
    if(d[i] == 1) 
      solve(i);
  }
  
  vi ans;
  int idx = max_element(d, d+n) - d;
  while(idx != -1){
    ans.pb(a[idx]);
    idx = path[idx];
  }
  cout << ans.size() << nl;
  for(auto it = ans.rbegin(); it < ans.rend(); it++) cout << *it << ' '; 
}