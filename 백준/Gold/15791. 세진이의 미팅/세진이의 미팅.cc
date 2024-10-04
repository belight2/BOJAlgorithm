#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll n, r;

ll fac(ll n){ return (n==1) ? 1 : (n * fac(n-1)) % MOD; }

ll rpow(ll x, int n){
    if(n == 1) return x;
    ll ret = rpow(x, n/2);
    ret = (ret * ret) % MOD;
    return ((n&1) ? (ret * x) %MOD : ret); 
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // input
    cin >> n >> r;

    // output
    cout << (fac(n) * rpow((fac(r) * fac(n-r))%MOD, MOD-2)) % MOD;
}