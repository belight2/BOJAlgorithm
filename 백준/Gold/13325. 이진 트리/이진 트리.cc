#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int h;
int tree[2'100'000];
int dist[2'100'000];
void dfs(int cur, int depth, int dst){
  dist[cur] = dst;
  if(depth == h) return;
  int l = cur * 2, r = cur * 2 + 1;
  dfs(l, depth+1, dst+tree[l]);
  dfs(r, depth+1, dst+tree[r]);
  dist[cur] = max(dist[l], dist[r]);
  int dif = abs(dist[l] - dist[r]);
  (dist[l] > dist[r]) ? tree[r] += dif : tree[l] += dif;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> h;
  int mxlen = (1 << (h+1)) - 1;
  for(int i = 2; i <= mxlen; i++) cin >> tree[i];
  dfs(1, 0, 0);
  int ans{};
  for(int i = 1; i <= mxlen; i++) ans += tree[i];
//#define DEBUG_
#ifndef DEBUG_
  cout << ans;
#endif
#ifdef DEBUG_
#endif
}