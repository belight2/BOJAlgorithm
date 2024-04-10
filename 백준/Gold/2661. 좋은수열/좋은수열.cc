#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
const char nl = '\n';
int n;
string cur,ans;
bool is_valid(){
  for(int dep = 1; dep <= cur.size()/2; dep++){
    bool flag = 1;
    for(int idx = cur.size()-1; cur.size()-1-idx < dep; idx--){
      if(cur[idx] != cur[idx-dep]) flag = 0;
    }
    if(flag) return 0;
  }
  return 1;
}

void back_t(int k){
  if(k == n){
    ans = cur;
    return;
  }  
  for(int i = 1; i <= 3; i++){
    if(ans.size()) return;
    cur.pb(i+'0');
    if(is_valid()) back_t(k+1);
    cur.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  back_t(0);
//#define DEBUG_
#ifndef DEBUG_
  cout << ans;
#endif
#ifdef DEBUG_
#endif
}