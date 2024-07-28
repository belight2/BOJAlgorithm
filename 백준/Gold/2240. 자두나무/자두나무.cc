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
int t, w, a[1005], d[1005][35];
int main() {
  fastio(nullptr, false);
  cin >> t >> w;
  for(int i = 1; i <= t; i++){
    cin >> a[i];
    d[i][0] = d[i-1][0];
    if(a[i]&1) d[i][0]++;
  }
  for(int j = 1; j <= w; j++){
    for(int i = 1; i <= t; i++){
      d[i][j] = max(d[i-1][j], d[i-1][j-1]);
      if((a[i]&1) && !(j&1)) d[i][j]++;
      else if(!(a[i]&1) && j&1 ) d[i][j]++;
    }
  }
  cout << *max_element(d[t], d[t]+w+1);
}