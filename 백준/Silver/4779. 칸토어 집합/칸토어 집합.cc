#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pi> qpi;
typedef queue<pl> qpl;
typedef queue<ti> qti;
typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

int tmp;

void solve(vc &vec, int n, int cx){
  if(n == 1) return;
  int mid = cx + n/3;
  solve(vec, n/3, cx);
  for(int i = mid; i < mid+n/3; i++) vec[i] = ' ';
  solve(vec, n/3, mid + n/3);
}

int main() {
  fastio(nullptr, false);
  while(cin >> tmp){
    int n = 1;
    for(int i = 0; i < tmp; i++) n *= 3;
    vc ans(n, '-');
    solve(ans, n, 0);
    for(auto &c : ans) cout << c;
    cout << nl;
  }
}