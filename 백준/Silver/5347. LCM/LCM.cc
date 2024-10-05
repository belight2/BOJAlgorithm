#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	if(a == 0) return b;
	return gcd(b%a, a);
}

long long lcm(long long a, long long b){
	return a / gcd(a,b) * b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		long long x, y;
		cin >> x >> y;
		cout << lcm(x,y) << '\n';
	}
}