#include <iostream>
using namespace std;

int GCD(int a, int b){
	if(a == 0 ) return b;
	return GCD(b%a, a);
}
int LCM(int a, int b){
	return a / GCD(a,b) * b;
}
int solve(int m, int n, int x, int y){
	if(x == m) x = 0;
	if(y == n) y = 0;
	int l = LCM(m,n);
	for(int i = x; i <= l; i += m){
		if(i == 0) continue;
		if(i % n == y) return i;
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, m, n, x, y;
	cin >> t;
	while(t--){
		cin >> m >> n >> x >> y;
		cout << solve(m,n,x,y) << '\n';
	}
}
