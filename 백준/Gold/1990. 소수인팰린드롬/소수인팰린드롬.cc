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
int a, b;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  // 에라토스테네스의 채 O(sqrt(100,000,000)) 가능
  vector<bool> isprime(b+1, 1);
  for(int i = 2; i * i <= b; i++){
    if(!isprime[i]) continue;
    for(int j = 2; j * i <= b; j++){
      isprime[i*j] = 0;
    }
  }
  //팰린드롬인지 확인
  for(int i = a; i <= b; i++){
    if(!isprime[i]) continue;
    string chk = to_string(i);
    if(chk.size() == 1){
      cout << chk << nl;
      continue;
    }
    int en = chk.size() - 1;
    int st = 0;
    bool flag = 1;
    while(st < en) if(chk[st++] != chk[en--]) flag = 0;
    if(flag) cout << chk << nl;
  }
  cout << -1;
  
//#define DEBUG_
#ifndef DEBUG_
#endif
#ifdef DEBUG_
  for(int i = 2; i <= b; i++){
    if(isprime[i]) cout << i << nl;
  }
#endif
}