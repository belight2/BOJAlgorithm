// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll f[21];
vector<bool> vis(21);
int n, sub;

void firstQuery(ll k){
  vector<int> ans{};
  
  for(int i = 1; i <= n; i++){
    int cnt = 1;
    for(int j = 1; j <= n; j++){
      if(vis[j])  continue;
      
      if(k <= cnt * f[n - i]){
        k -= (cnt - 1) * f[n - i];
        ans.push_back(j);
        vis[j] = 1;
        break;
      }
      cnt++;
    } 
  }

  for(auto x : ans) cout << x << ' ';
}

void secondQuery(vector<int> &a){
  long k = 1;
  for(int i = 1; i <= n; i++){
    long cnt = 0;
    for(int j = 1; j < a[i]; j++) if(!vis[j]) {
      cnt++;
    }
    k += cnt * f[n - i];
    vis[a[i]] = 1;
  }

  cout << k;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  f[0] = f[1] = 1;
  for(int i = 2; i <= 20; i++) f[i] = f[i-1] * i;

  cin >> n >> sub;

  if(sub & 1){
    ll k; cin >> k;
    firstQuery(k);
  }
  else{
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    secondQuery(a);
  }
}