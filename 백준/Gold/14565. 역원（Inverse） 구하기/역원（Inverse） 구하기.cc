#include <iostream>
#include <tuple>
#define ll long long
using namespace std;
ll n, a;
tuple<ll, ll, ll> xGCD(ll a, ll b){
	if(a == 0) return make_tuple(b, 0, 1);
	ll gcd, x, y;
	tie(gcd, x, y) = xGCD(b%a, a);
	return make_tuple(gcd, y - (b/a)*x, x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a;
	ll gcd, x, y;
	tie(gcd, x, y) = xGCD(n, a);
	if(y < 0) y += n;
	if(gcd != 1) y = -1;
	cout << n - a << ' ' << y;
}
