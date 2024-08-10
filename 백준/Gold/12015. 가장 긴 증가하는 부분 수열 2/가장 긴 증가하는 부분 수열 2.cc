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

int n;
int tree[2'000'005];
pi a[1'000'005];

int mxq(int l, int r){
  int ret{};
  for(l += n, r += n; l < r; l>>=1, r>>=1){
    if(l&1) ret = max(ret, tree[l++]);
    if(r&1) ret = max(ret, tree[--r]);
  }
  return ret;
}

void update(int p, int val){
  p += n;
  tree[p] = val;
  for(int i = p; i > 1; i >>= 1) tree[i>>1] = max(tree[i], tree[i^1]);
}

bool cmp(const pi &a, const pi &b){
  if(a.X == b.X) return a.Y > b.Y;
  return a.X < b.X;
}
int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i].X;
    a[i].Y = i;
  }
  sort(a, a+n, cmp);
  for(int i = 0; i < n; i++){
    int mx = mxq(0, a[i].Y) + 1;
    update(a[i].Y, mx);
  }
  cout << tree[1];
}