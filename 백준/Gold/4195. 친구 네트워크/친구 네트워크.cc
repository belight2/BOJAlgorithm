#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
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

vector<int> p(200'005, -1);

int find(int x){
  return (p[x] < 0 ? x : p[x] = find(p[x]));
}

int merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return abs(p[x]);
  if(p[x] > p[y]) swap(x, y);
  p[x] += p[y];
  p[y] = x;
  return abs(p[x]);
}

void solve(){
  fill(all(p), -1);

  cin >> n;

  int cnt = 1;
  unordered_map<string, int> idx;

  string a, b;
  while(n--){
    cin >> a >> b;
    if(idx.find(a) == idx.end()) idx[a] = cnt++;
    if(idx.find(b) == idx.end()) idx[b] = cnt++;
    cout << merge(idx[a], idx[b]) << '\n';
  }
}

int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--) solve();
}