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
int n, flag;
ll bit[32];
void chk_row(){
  for(int i = 0; i < n; i++){
    int cnt{};
    for(int j = 0; j < n; j++)
      if((bit[i]>>j)&1) cnt++;
    if(cnt <= n / 2) bit[i] = 0;
  }
}
void chk_col(){
  for(int i = 0; i < n; i++){
    int cnt{};
    for(int j = 0; j < n; j++){
      if((bit[j] >> i)&1) cnt++;
    }
    if(cnt > n / 2) continue;
    for(int j = 0; j < n; j++){
      bit[j] &= (~(1 << i));
    }
  }
}
int main() {
  fastio(nullptr, false);
  cin >> n >> flag;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int cur;
      cin >> cur;
      if(cur) bit[i] |= (1 << (n-j-1));
    }
    if(flag) bit[i] = ~bit[i];
  }
  for(int i = 0; i < 2; i++){
    chk_row();
    chk_col();
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if((bit[i] >> i)&1){
        cout << 0;
        return 0;
      }
    }
  }
  cout << 1;
}