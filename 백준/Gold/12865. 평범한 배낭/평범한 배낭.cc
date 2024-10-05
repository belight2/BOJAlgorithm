#include <iostream>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;
pair<int,int> obj[105]; // 무게, 가치
int dp[105][100005];
int n, k;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	obj[0] = { 0, 0 };
	for(int i = 1; i <= n; i++){
		cin >> obj[i].X >> obj[i].Y;
	}
	for(int w = 1; w <= k; w++){
		for(int i = 1; i <= n; i++){
			if( obj[i].X <= w ){
				dp[i][w] = max(dp[i-1][w-obj[i].X] + obj[i].Y, dp[i-1][w]);
			}
			else dp[i][w] = dp[i-1][w];
		}
	}
	
	cout << dp[n][k];
}
