#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MOD 1'000'000'000
const char nl = '\n';
int n;
int d[21][1'000'001];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i <= 20; i++) d[i][0] = 1;

  for(int i = 1; i <= n; i++){
    d[0][i] = d[0][i-1];
    for(int j = 1; j <= 20; j++){
      d[j][i] = ((1 << j) <= i) ? (d[j-1][i] + d[j][i-(1 << j)]) % MOD : d[j-1][i];
    }
  }
  cout << d[20][n];
}