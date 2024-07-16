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
const char nl = '\n';
const int INF = 1e9;
int n;
int h[4];
int d[70][70][70];
int dmg[6][3] = {
  { 9, 3, 1 },
  { 9, 1, 3 },
  { 3, 9, 1 },
  { 3, 1, 9 },
  { 1, 9, 3 },
  { 1, 3, 9 }
};
int dp(int a, int b, int c){
  if(a <= 0 && b <= 0 && c <= 0) return 0;
  a = max(a, 0);
  b = max(b, 0);
  c = max(c, 0);
  if(d[a][b][c] != INF) return d[a][b][c];
  for(int i = 0; i < 6; i++) d[a][b][c] = min(d[a][b][c], 1 + dp(a-dmg[i][0], b - dmg[i][1], c - dmg[i][2]));
  return d[a][b][c];
}
int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> h[i];
  fill(&d[0][0][0], &d[60][60][61], INF);
  cout << dp(h[0], h[1], h[2]);
}