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
int n, k;
pi w[105], b[105];
int d[105][100'005];
int main() {
  fastio(nullptr, false);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> w[i].X >> w[i].Y >> b[i].X >> b[i].Y;
  d[1][w[1].X] = w[1].Y;
  d[1][b[1].X] = max(d[1][b[1].X], b[1].Y);
  for(int i = 1; i <= n-1; i++){
    for(int j = 0; j <= k; j++){
      if(!d[i][j]) continue;
      if(j+w[i+1].X <= k) d[i+1][j+w[i+1].X] = max(d[i+1][j+w[i+1].X], d[i][j] + w[i+1].Y);
      if(j+b[i+1].X <= k) d[i+1][j+b[i+1].X] = max(d[i+1][j+b[i+1].X], d[i][j] + b[i+1].Y);
    }
  }
  cout << *max_element(d[n], d[n]+k+1);
}