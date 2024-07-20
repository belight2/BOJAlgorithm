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
int n;
int a[5005];
int d[5005][5005];
int dp(int st, int en){
  if(st >= en) return 0;
  if(d[st][en] != -1) return d[st][en];
  if(a[st] == a[en]) return dp(st+1, en-1);
  return d[st][en] = min(1+dp(st+1, en), 1+dp(st, en-1));
}
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  memset(d, -1, sizeof(d));
  cout << dp(0, n-1);
}