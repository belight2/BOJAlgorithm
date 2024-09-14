// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> prime;

// 1부터 n까지의 소수를 구해줌 O(n)
void eratos(int n){
  vector<bool> isprime(n+1, 1);
  for(int i = 2; i * i <= n; i++){
    if(!isprime[i]) continue;
    for(int j = i * i; j <= n; j += i) isprime[j] = 0;
  }
  for(int i = 2; i <= n; i++) if(isprime[i]) prime.push_back(i);
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n;
  eratos(n);

  // solve, 투 포인터를 사용한다.
  int ans{}, tot{}, en{};
  for(int st = 0; st < prime.size(); st++){
    while(en < prime.size() && tot < n) tot += prime[en++];
    if(tot == n) ans++;
    tot -= prime[st];
  }

  // output
  cout << ans;
}