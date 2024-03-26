#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll solve(ll k){
	return floor(2*sqrt(k) - 1e-9);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	ll x, y;
	while(t--){
		cin >> x >> y;
		cout << solve(y - x) << '\n';
	}
}
