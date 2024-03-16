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
int n;
int INF = 0x3f3f3f3f;
int d[2][2][5];
void solve(){
  int x;
  for(int i = 1; i <= 3; i++){
    cin >> x;
    d[1][0][i] = min({d[0][0][max(i-1, 1)], d[0][0][i], d[0][0][min(i+1, 3)]}) + x;
    d[1][1][i] = max({d[0][1][max(i-1, 1)], d[0][1][i], d[0][1][min(i+1, 3)]}) + x; 
  } 
  memcpy(d[0], d[1], sizeof(d[1]));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= 3; i++){
    cin >> d[0][0][i];
    d[0][1][i] = d[0][0][i];
  }
  for(int t = 1; t < n; t++) solve();
  cout << *max_element(d[0][1], d[0][1]+4) << ' ' << *min_element(d[0][0]+1, d[0][0]+4);
}