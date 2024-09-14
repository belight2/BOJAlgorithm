#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b%a, a);
}
void solve(){
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for(int i = 0 ; i < n; i++){
		cin >> v[i];
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			ans += gcd(v[i], v[j]);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) solve();
}