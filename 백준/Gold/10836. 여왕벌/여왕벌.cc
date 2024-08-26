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

int main() {
  fastio(nullptr, false);

  cin >> n >> m;
  vector<vi> h(n, vi(n, 1)); // 벌집
  vi g(2*n-1, 0);
  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    int i{};
    while(a--) i++;
    while(b--) g[i++] += 1;
    while(c--) g[i++] += 2;
  }
  int cx = n-1, cy = 0;
  for(int idx = 0; idx < sz(g); idx++){
    if(cx > 0) h[cx--][cy] += g[idx];
    else h[cx][cy++] += g[idx];
  }

  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      h[i][j] = max({h[i-1][j-1], h[i][j-1], h[i-1][j]});
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << h[i][j] << ' ';
    }
    cout << nl;
  }
}