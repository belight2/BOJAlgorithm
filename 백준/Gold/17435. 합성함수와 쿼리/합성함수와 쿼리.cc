#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define log2(x) long(log10(x)/log10(2)) + 2;
using namespace std;
const char nl = '\n';
const int MXN = 200005;
const int MXK = log2(500005);
int m;
int nxt[MXK][MXN];
void query(){
  int n, x;
  cin >> n >> x;
  for(int i = MXK; i >= 0; i--)
    if(n&(1 << i)) x = nxt[i][x];
  cout << x << nl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m;
  for(int i = 1; i <= m; i++) cin >> nxt[0][i];
  for(int k = 1; k < MXK; k++){
    for(int i = 1; i <= m; i++){
      nxt[k][i] = nxt[k-1][nxt[k-1][i]];
    }
  }
  int Q;
  cin >> Q;
  while(Q--) query();
}