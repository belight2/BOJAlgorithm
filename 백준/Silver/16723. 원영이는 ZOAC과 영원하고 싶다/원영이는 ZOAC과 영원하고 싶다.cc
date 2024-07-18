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
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int s[8] = { 0, 2, 4, 2, 8, 2, 4, 2 };
int n;
ll solve(int t){
  ll ret{};
  for(int i = 0; (1 << i) <= t; i++){
    int a = (t+(1<<i));
    int b = (1 << (i+1));
    ret +=  a / b * b;
  }
  return ret;
}
int main(){
  fastio(nullptr, false);
  cin >> n;
  cout << solve(n);
}