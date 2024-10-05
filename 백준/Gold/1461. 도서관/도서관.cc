#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using pi = pair<int,int>;
const char nl = '\n';
int n, m, x;
vector<int> neg;
vector<int> pos;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(n--){
    cin >> x;
    (x < 0) ? neg.pb(-x) : pos.pb(x);
  }
  int res = 0;
  sort(rall(neg));
  sort(rall(pos));
  for(int i = 0; i < neg.size(); i+=m) res += 2*neg[i];
  for(int i = 0; i < pos.size(); i+=m) res += 2*pos[i];
  res -= (!pos.empty() && !neg.empty()) ? ( (pos[0] > neg[0]) ? pos[0] : neg[0] ) : ((pos.empty()) ? neg[0] : pos[0] );
  cout << res;
}