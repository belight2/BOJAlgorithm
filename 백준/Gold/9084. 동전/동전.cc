#include <iostream>
#include <algorithm>
using namespace std;
int t; // 테스트케이스
int n; // 동전의 개수
int m; // 동전으로 만들어야 할 금액 
int val[20]; // 각 동전의 가치 
int dp[10001]; // 동전으로 세울 수 있는 가지 수
void solve(){
	int cur;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> val[i];
	cin >> m; 
	fill(dp, dp+ m + 1 ,0);
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int k = val[i]; k <= m; k++){
			dp[k] += dp[k-val[i]];
		}
	}
	cout << dp[m] << '\n';
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--){
		solve();
	} 
}
