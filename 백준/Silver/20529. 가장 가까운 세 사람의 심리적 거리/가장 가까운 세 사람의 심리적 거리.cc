#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int n;
vector<string> mbti(35);
int cal_distance(const string &a, const string &b, const string &c){
  int ans = 0;
  for(int i = 0; i < 4; i++) ans += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
  return ans;
}
int solve(){
  cin >> n;
  if(n > 32 || n <= 2) return 0;
  for(int i = 0; i < n; i++) cin >> mbti[i];
  int res = 1e9+1;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      for(int k = j+1; k < n; k++){
        res = min(res, cal_distance(mbti[i], mbti[j], mbti[k]));
      }
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t{};
  cin >> t;
  while(t--) cout << solve() << nl;
}