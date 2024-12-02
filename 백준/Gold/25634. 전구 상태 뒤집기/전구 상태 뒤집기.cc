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
int a[200'005], b[200'005], d[200'005];

int main() {
  fastio(nullptr, false);

  // init
  int tot{};

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  
  for(int i = 0; i < n; i++){
    cin >> b[i];
    if(b[i]) tot += a[i];  
  }

  // solve
  d[0] = (b[0] ? -a[0] : a[0]);
  for(int i = 1; i < n; i++){
    d[i] = b[i] ? max(d[i-1] - a[i], -a[i]) : max(d[i-1] + a[i], a[i]);
  }

  // output
  cout << tot + *max_element(d, d+n);
}