// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll solution[5005];

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> solution[i];

  // solve
  ll ans1, ans2, ans3;
  ans1 = ans2 = ans3 = 1e9+1;
  
  sort(solution, solution+n);
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      int idx = lower_bound(solution, solution+n, -solution[i]-solution[j]) - solution;

      // 이번엔 idx-2, idx-1, idx, idx+1, idx+2 중에 답이 있음
      for(int k = -2; k <= 2; k++){
        if(idx+k == i || idx+k == j) continue;
        if(idx+k < 0 || idx+k >= n) continue;
        if(abs(solution[i] + solution[j] + solution[idx+k]) < abs(ans1+ans2+ans3)){
          tie(ans1, ans2, ans3) = {solution[i], solution[j], solution[idx+k]};
        }
      }
    }
  }

  // output
  vector<ll> ans{ans1, ans2, ans3};
  sort(ans.begin(), ans.end());  
  for(auto &x : ans) cout << x << ' ';
}