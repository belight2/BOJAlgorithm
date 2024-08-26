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

  cin >> m >> n;

  vi g(2*m-1, 1);

  while(n--){
    int a, b, c;
    cin >> a >> b >> c;
    for(int idx = a; idx < a + b; idx++) g[idx]++;
    for(int idx = a+b; idx < sz(g); idx++) g[idx]+=2;
  }
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      cout << (j == 0 ? g[m - i - 1] : g[m + j - 1]) << " ";
    }
    cout << nl;
  }
}