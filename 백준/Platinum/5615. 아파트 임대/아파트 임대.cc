#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;
vector<ull> alist = { 2, 3, 5, 7, 11 };

ull powmod(ull x, ull y, ull m){
	x %= m;
	ull r = 1ULL;
	while( y > 0){
		if(y % 2 == 1) r = r * x % m;
		x = x*x%m;
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
	if(x == 1 || x == n - 1) return true;
	for(int i = 0; i < r - 1; i++){
		x = powmod(x, 2, n);
		if( x == n - 1) return true;
	}
	return false;
}
bool is_prime(ull n){
	if(n <= 1) return 0;
	if(n == 2 || n == 3 ) return 1;
	if( n % 2 == 0 ) return 0; 
	for(ull a : alist){
		if(n == a) return 1;
		if(!miller_rabin(n,a)) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ull s;
	int n; cin >> n;
	int ans = 0;
	while(n--){
		cin >> s;
		if(is_prime(2*s+1)) ans++;
	}
	cout << ans;
}
