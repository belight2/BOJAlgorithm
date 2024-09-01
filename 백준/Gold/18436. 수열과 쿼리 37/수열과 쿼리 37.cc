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
pi tree[200'005]; // { 홀, 짝 }

void update(int p, int val){
  p += n;
  tree[p] = (val&1) ? make_pair(1, 0) : make_pair(0, 1);
  for(int i = p; i > 1; i>>=1){
    tree[i>>1] = {tree[i].X + tree[i^1].X, tree[i].Y + tree[i^1].Y };
  }
}

pi query(int l, int r){
  pi ret;
  for(l+=n, r+=n; l < r; l>>=1, r>>=1){
    if(l&1) ret = {ret.X + tree[l].X, ret.Y + tree[l++].Y};
    if(r&1) ret = {ret.X + tree[--r].X, ret.Y + tree[r].Y};
  }
  return ret;
}

int main() {
  fastio(nullptr, false);
  cin >> n;

  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    (num&1) ? tree[i+n].X = 1 : tree[i+n].Y = 1;
  }

  for(int i = n-1; i > 0; --i){
    tree[i] = {tree[i<<1].X + tree[i<<1|1].X, tree[i<<1].Y + tree[i<<1|1].Y};
  }

  cin >> m;
  while(m--){
    int cmd, l, r;
    cin >> cmd >> l >> r;
    if(cmd == 1) update(l-1, r);
    else{
      auto ret = query(l-1, r);
      cout << (cmd == 2 ? ret.Y : ret.X) << '\n';
    }
  }


}