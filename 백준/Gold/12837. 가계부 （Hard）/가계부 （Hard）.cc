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

int n, q;
ll tree[2'000'005];

void update(int p, ll val){
  p += n;
  tree[p] += val;
  for(int i = p; i > 1; i>>=1) tree[i>>1] = tree[i] + tree[i^1];
}

ll query(int l, int r){
  ll ret{};
  for(l += n, r += n; l < r; l>>=1, r>>=1){
    if(l&1) ret += tree[l++];
    if(r&1) ret += tree[--r];
  }
  return ret;
}

int main() {
  fastio(nullptr, false);
  cin >> n >> q; 
  while(q--){
    ll cmd, p, x;
    cin >> cmd >> p >> x;
    if(--cmd) cout << query(p-1, x) << nl;
    else update(p-1, x);
  }
}