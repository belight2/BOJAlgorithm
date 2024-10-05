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

const int MOD = 1000;
int n;
ll b;

vector<vi> matmul(const vector<vi> &a, const vector<vi> &b){
  vector<vi> ret(n, vi(n));
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return ret;
}

vector<vi> rpow(vector<vi> &A, ll x){
  if(x == 1) return A;
  auto ret = rpow(A, x/2);
  ret = matmul(ret, ret);
  if(x&1) ret = matmul(ret, A);
  return ret;
}

int main() {
  fastio(nullptr, false);
  
  cin >> n >> b;
  vector<vi> a(n, vi(n));
  for(auto &row : a){
    for(auto &col : row) cin >> col;
  }

  auto ans = rpow(a, b);
 
  for(auto &row : ans){
    for(auto &col : row) cout << col%MOD << ' ';
    cout << nl;
  }
}