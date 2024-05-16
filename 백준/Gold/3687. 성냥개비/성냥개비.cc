#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define null ""
const char nl = '\n';
int n;
int cost[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
bool cmp(const string &a, const string &b){
  if(a.size() == b.size()){
    for(int i = 0; i < a.size(); i++){
      if(a[i] == b[i]) continue;
      return a[i] < b[i];
    }
  }
  return a.size() < b.size();
}
void solve(){
  cin >> n;
  vs mxdp(n+1, null);
  vs mndp(n+1, null);
  for(int i = 0; i <= n; i++){
    for(int j = 0; j < 10; j++){
      if(i + cost[j] > n) continue;
      if(i == 0 || mxdp[i] != null){
        string mxn = mxdp[i] + to_string(j);
        if(mxn != "0" && (mxdp[i+cost[j]] == null || cmp(mxdp[i+cost[j]], mxn)))
          mxdp[i+cost[j]] = mxn;
      }
      if(i == 0 || mndp[i] != null){
        string mnn = mndp[i] + to_string(j);
        if(mnn != "0" && (mndp[i+cost[j]] == null || cmp(mnn, mndp[i+cost[j]])))
          mndp[i+cost[j]] = mnn;
      }
    }
  }
  cout << mndp[n] << " " << mxdp[n] << nl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t{};
  cin >> t;
  while(t--) solve();
}