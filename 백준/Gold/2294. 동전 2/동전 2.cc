#include <iostream>
#include <algorithm>
using namespace std;
int dp[10005];
int cost[105];
int n, k;
const int INF = 0x3f3f3f3f;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> cost[i];
	
	fill(dp+1, dp+k+1, INF);
	// 점화식 
	for(int i = 1; i <= n; i++){
		for(int val = 1; val <= k; val++){
			if(cost[i] <= val) dp[val] = min(dp[val], dp[val-cost[i]]+1);
		}
	}
	if(dp[k] == INF) cout << -1; else cout << dp[k];
	
}
