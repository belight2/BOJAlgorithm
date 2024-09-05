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

int main() {
  fastio(nullptr, false);

  cin >> n;
  
  vi a(n);
  for(auto &x : a) cin >> x;

  vector<vi> d(2, vi(n));

  for(int i = 0; i < n; i++){
    int cur = a[i];
    for(int j = i+1; j < n; j++){
      int nxt = a[j];
      if(cur < nxt) d[0][j] = max(d[0][j], d[0][i] + 1);
      else if(cur > nxt) d[1][j] = max({d[1][j], d[1][i] + 1, d[0][i] + 1});
    }
  }

  cout << max(*max_element(all(d[0])), *max_element(all(d[1]))) + 1;
}