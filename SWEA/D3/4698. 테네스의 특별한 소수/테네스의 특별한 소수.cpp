#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int,int,int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
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

vector<bool> isprime(1'000'005, 1);
vector<int> prime;

void eratos(){
  isprime[0] = isprime[1] = 0;
  for(int i = 2; i * i <= 1'000'000; i++){
    if(!isprime[i]) continue;
    prime.pb(i);
    for(int j = i * i; j <= 1'000'000; j+=i){
      isprime[j] = 0;
    }
  }
  for(int j = prime.back()+1; j <= 1'000'000; j++) if(isprime[j]) prime.pb(j);
}

char d;
int a, b;
int ans;

void solve(){
  ans = 0;
  cin >> d >> a >> b;
  auto st = lower_bound(prime.begin(), prime.end(), a);
  while(st != prime.end() && *st <= b){
    string str = to_string(*st);
    for(auto &c : str){
      if(c != d) continue;
      ans++;
      break;
    }
    st++;
  }
  cout << ans << nl;
}

int main() {
  fastio(nullptr, false);
  eratos();
  int t{};
  cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "#" << i << " ";
    solve();
  }
}