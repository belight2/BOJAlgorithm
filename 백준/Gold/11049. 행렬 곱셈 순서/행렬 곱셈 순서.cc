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
pi mat[505];
int d[505][505];

int dp(int st, int en){
  if(d[st][en] != -1) return d[st][en];
  if(en - st == 1) return mat[st].X * mat[en].X * mat[en].Y;
  d[st][en] = dp(st, st) + dp(st+1, en) + mat[st].X * mat[st].Y * mat[en].Y;
  for(int mid = st+1; mid < en; mid++){
    d[st][en] = min(d[st][en], dp(st, mid) + dp(mid+1, en) + mat[st].X * mat[mid].Y * mat[en].Y);
  }
  return d[st][en];
}

int main() {
  fastio(nullptr, false);

  // input  
  cin >> n;
  for(int i = 0; i < n; i++) cin >> mat[i].X >> mat[i].Y;

  // solve
  memset(d, -1, sizeof(d));
  for(int i = 0; i < n; i++) d[i][i] = 0;
  cout << dp(0, n-1);
}