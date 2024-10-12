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

int n;
bool isprime(ll x){
  if(x == 1) return 0;
  for(int i = 2; i * i <= x; i++)
    if(x%i == 0) return 0;
  return 1;
}

void solve(ll cur, int k){
  // base condition
  if(k == n){
    cout << cur << nl; 
    return;
  }

  for(int i = 1; i <= 9; i++){
    ll nxt = cur*10 + i;
    if(isprime(nxt)) solve(nxt, k+1);
  }
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  
  // solve
  solve(0, 0);
}