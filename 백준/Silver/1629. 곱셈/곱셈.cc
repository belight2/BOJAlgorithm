#include <iostream>

using namespace std;

using ll = long long;

ll solve(ll a, ll b, ll c){
	if( b == 1 ) return a % c;
	ll val = solve(a, b/2, c);
	val = val * val % c;
	if( b % 2 == 0 ) return val;
	return val * a % c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,c;
	cin >> a >> b >> c;
	cout << solve(a,b,c);
}