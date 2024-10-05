#include <iostream>
using namespace std;
long long dp[34];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	dp[0] = 1;
	dp[2] = 3;
	for(int i = 4; i <= n; i++){
		if(!(i&1)){
			dp[i] = dp[i-2] * 3;
			for(int j = 4; j <= i; j+=2){
				dp[i] += dp[i-j]*2;
			}
		} 
	}
	cout << dp[n];
}
