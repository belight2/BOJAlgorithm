#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll n, r;
ll f[1'000'005];

ll rpow(ll x, int n){
    if(n == 1) return x;
    ll ret = rpow(x, n/2);
    ret = (ret * ret) % MOD;
    return ((n&1) ? (ret * x) %MOD : ret); 
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    f[0] = f[1] = 1;
    for(int i = 2; i <= 1'000'000; i++) f[i] = (i * f[i-1]) % MOD;
    
    // input
    cin >> n >> r;

    // output
    cout << (f[n] * rpow((f[r] * f[n-r])%MOD, MOD-2)) % MOD;
}