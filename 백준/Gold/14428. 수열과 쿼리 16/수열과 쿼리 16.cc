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

int n, m;
int a[100'005];
int tree[200'005];

void update(int p, int val){
  a[p] = val;
  p += n;
  for(int i = p; i > 0; i >>= 1){
    int l = tree[i];
    int r = tree[i^1];
    if(a[l] == a[r]) tree[i>>1] = min(l, r);
    else if(a[l] < a[r]) tree[i>>1] = l;
    else tree[i>>1] = r;
  }
}

int query(int l, int r){
  int ret = n;
  for(l += n, r += n; l < r; l >>= 1, r >>= 1){
    if(l&1){
      if(a[ret] == a[tree[l]]) ret = min(ret, tree[l]);
      else if(a[ret] > a[tree[l]]) ret = tree[l];
      l++;
    }
    if(r&1){
      --r;
      if(a[ret] == a[tree[r]]) ret = min(ret, tree[r]);
      else if(a[ret] > a[tree[r]]) ret = tree[r];
    }
  }
  return ret;
}

int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    tree[i+n] = i;
  }
  a[n] = 1e9+10;
  for(int i = n-1; i > 0; i--){
    int l = tree[(i<<1)];
    int r = tree[(i<<1|1)];
    if(a[l] == a[r]) tree[i] = min(l, r);
    else if(a[l] < a[r]) tree[i] = l;
    else tree[i] = r;
  }


  cin >> m;
  while(m--){
    int cmd, l, r;
    cin >> cmd >> l >> r;
    if(--cmd) cout << query(l-1, r)+1 << nl;
    else update(l-1, r);
  }
}