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

vi tree;

void postorder(int s, int e){
  if(s >= e) return;
  int x = s+1;
  while(x < e && tree[s] > tree[x]) x++;
  postorder(s+1, x);
  postorder(x, e);
  cout << tree[s] << nl;
}

int main() {
  fastio(nullptr, false);
  int x;
  while(cin >> x) tree.pb(x);
  postorder(0, sz(tree));
}