#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define ll long long
using namespace std;
using pl = pair<ll, ll>;
const char nl = '\n';
const ll mod = 1e9+7;
ll GCD(ll a, ll b){
	if(a == 0) return b;
	return GCD(b%a, a);
}
pl rpow(ll n){
	if(n == 1) return {1L, 0L};
	ll x, y; tie(x,y) = rpow(n/2);
	pl res{x*(x+2*y)%mod, (x*x+y*y)%mod};
	if(n&1) res = { (res.X+res.Y)%mod, res.X };
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n{}, m{};
	cin >> n >> m;
	cout << rpow(GCD(n,m)).X;
}