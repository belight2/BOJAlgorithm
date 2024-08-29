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
// 밀러-라빈 소수 판별법
vector<ull> alist = { 2, 3, 5, 7, 11 };

ull powmod(ull x, ull y, ull m){
  x %= m;
  ull r = 1ULL;
  while(y > 0){
    if(y % 2 == 1) r = r * x % m;
    x = x * x % m;
    y /= 2;
  }
  return r;
}

inline bool miller_rabin(ull n, ull a){
  ull r = 0;
  ull d = n - 1;
  
  while(d % 2 == 0){
    r++;
    d = d >> 1;
  }

  ull x = powmod(a, d, n);

  if(x == 1 || x == n-1) return 1;
  
  for(int i = 0; i < r - 1; i++){
    x = powmod(x, 2, n);
    if(x == n - 1) return 1;
  }
  
  return 0;
}
bool is_prime(ull n){
  if(n <= 1) return 0;
  if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11) return 1;
  if(n % 2 == 0) return 0;
  if(n < 1'000'000){
    for(ull i = 3; i * i <= n; i++){
      if(n%i == 0) return 0;
    }
    return 1;
  }
  else{
    for(ull a : alist){
      if(!miller_rabin(n, a))
        return 0;
    }
    return 1;
  }
}
int main() {
  fastio(nullptr, false);
  int t{};
  cin >> t;
  while(t--){
    ull x;
    cin >> x;
    while(!is_prime(x)) x++;
    cout << x << nl;
  }
}