#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
vector<vi> a(10, vi(10, 0));
vi stk(6, 5);
int ans = 30, cnt;
bool check(int row, int col, int sz){
  if(row + sz > 10 || col + sz > 10) return 0;
  for(int i = 0; i < sz; i++){
    for(int j = 0; j < sz; j++){
      if(!a[row+i][col+j]) return 0;
    }
  }
  return 1;
}
void fill(int row, int col, int val, int sz){
  for(int i = 0; i < sz; i++)
  for(int j = 0; j < sz; j++)
    a[row+i][col+j] = val;
}
void back_t(int m, int row, int col){
  if(ans < m) return;
  if(cnt == 0){
    ans = min(ans, m);
    return;
  }
  for(int i = row; i < 10; i++){
    for(int j = col; j < 10; j++){
      if(!a[i][j]) continue;
      for(int k = 5; k > 0; k--){
        if(!check(i, j, k)) continue;
        if(stk[k] == 0) continue;
        fill(i, j, 0, k);
        stk[k]--;
        cnt -= k * k;
        back_t(m+1, 0, 0);
        cnt += k * k;
        stk[k]++;
        fill(i, j, 1, k);
      }
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 10; i++)
  for(int j = 0; j < 10; j++){
    cin >> a[i][j];
    if(a[i][j]) cnt++;
  }
  back_t(0, 0, 0);

//#define DEBUG_
#ifndef DEBUG_
  cout << ( ans == 30 ? -1 : ans );
#endif
#ifdef DEBUG_
cout << cnt << nl;
for(auto cur : a){
    for(int x : cur){
      cout << x << ' ';
    }
    cout << nl;
  }
#endif
}