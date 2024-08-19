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

int CCW(pi a, pi b, pi c){
  int ans = (a.X * b.Y + b.X * c.Y + c.X * a.Y) - (a.X * c.Y + c.X * b.Y + b.X * a.Y);
  if(ans == 0) return 0;
  return (ans > 0) ? 1 : -1;
}

int main() {
  fastio(nullptr, false);
  vpi p(3);
  for(auto &cur : p) cin >> cur.X >> cur.Y;
  cout << CCW(p[0], p[1], p[2]);
}