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
const int INF = 1e9;
int n;
int a[22][22];
int d[22][(1<<20)+1];

int main() {
  fastio(nullptr, false);
  cin >> n;
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];

  fill(&d[0][0], &d[n-1][(1<<n)]+sizeof(int), INF);
  for(int i = 0; i < n; i++)  d[0][1<<i] = a[0][i];
   
  for(int i = 1; i < n; i++){
    for(int j = 0; j < (1<<n); j++){
      if(d[i-1][j] == INF) continue;
      for(int k = 0; k < n; k++){
        if((j>>k)&1) continue;
        d[i][(j|(1<<k))] = min(d[i][(j|(1<<k))], d[i-1][j] + a[i][k]);
      }
    }
  }
  cout << d[n-1][(1<<n)-1]; 
}