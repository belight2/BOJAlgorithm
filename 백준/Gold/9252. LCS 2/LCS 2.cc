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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int n, m;
int d[1001][1001];
string a, b;
void print(int x, int y){
  if(d[x][y] == 0) return;
  if(a[x-1] == b[y-1]){
    print(x-1, y-1);
    cout << a[x-1];
  }
  else d[x-1][y] > d[x][y-1] ? print(x-1, y) : print(x, y-1);
}
int main() {
  fastio(nullptr, false);
  cin >> a >> b;
  n = a.size();
  m = b.size();
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i-1] == b[j-1]){
        d[i][j] = d[i-1][j-1] + 1;
      }
      else if(d[i-1][j] > d[i][j-1]){
        d[i][j] = d[i-1][j];
      }
      else{
       d[i][j] = d[i][j-1];
      }
    }
  }
  cout << d[n][m] << nl;
  print(n, m);
}