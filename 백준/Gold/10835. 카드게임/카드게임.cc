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
int n, l[2005], r[2005], d[2005][2005];
int solve(int lidx, int ridx){
  if(lidx == n || ridx == n) return 0;
  if(d[lidx][ridx] != -1) return d[lidx][ridx];
  if(l[lidx] > r[ridx]) d[lidx][ridx] = solve(lidx, ridx+1) + r[ridx];
  d[lidx][ridx] = max({d[lidx][ridx], solve(lidx+1, ridx), solve(lidx+1, ridx+1)});
  return d[lidx][ridx];
} 
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  for(int i = 0; i < n; i++) cin >> r[i];
  memset(d, -1, sizeof(d));
  cout << solve(0, 0);
}