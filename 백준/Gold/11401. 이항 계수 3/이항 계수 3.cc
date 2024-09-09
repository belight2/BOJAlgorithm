#include <iostream>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;

ull rpow(ull x, ull n){
	if(n == 1) return x % mod;
	ull val = rpow(x, n/2);
	val = (val * val) % mod;
	if(n&1) return val * x % mod; 
	return val;
}
ull fac(ull n){
	if(n == 0) return 1;
	return n * fac(n-1) % mod;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ull n, k;
	cin >> n >> k;
	ull a = fac(n);
	cout << (a * rpow((fac(k) * fac(n-k)) % mod, mod-2)) % mod;
}
