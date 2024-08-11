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

const int MOD = 1e9 + 7;

const ll adj[8][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 0, 1},
  {0, 0, 0, 0, 1, 0, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 0}
};

int d;

vector<vl> rpow(vector<vl> n, int x){
  if(x == 1) return n;
  
  auto mat = rpow(n, x/2);
  vector<vl> ret1(8, vl(8));
  vector<vl> ret2(8, vl(8));

  for(int k = 0; k < 8; k++){
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        ret1[i][j] = (ret1[i][j] + mat[i][k] * mat[k][j]) % MOD;
      }
    }
  }
  
  if(x&1){
    for(int k = 0; k < 8; k++){
      for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
          ret2[i][j] = (ret2[i][j] + ret1[i][k] * adj[k][j]) % MOD;
        }
      }
    }
  }
  return (x&1) ? ret2 : ret1;
}
int main() {
  fastio(nullptr, false);
  vector<vl> a(8, vl(8));
  for(int i = 0; i < 8; i++)
  for(int j = 0; j < 8; j++)
    a[i][j] = adj[i][j];
  
  cin >> d;

  cout << rpow(a, d)[0][0];
}