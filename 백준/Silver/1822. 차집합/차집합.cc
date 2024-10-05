// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> A, B;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  
  // input
  cin >> n >> m;
  A.resize(n); 
  B.resize(m);
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < m; i++) cin >> B[i];

  // solve
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<int> ans;
  for(auto &val : A){
    if(binary_search(B.begin(), B.end(), val)) continue;
    ans.push_back(val);
  }

  // output
  if(ans.empty()){
    cout << 0;
    return 0; // 프로그램 종료
  }
  cout << ans.size() << '\n';
  for(auto &val : ans) cout << val << ' ';
}