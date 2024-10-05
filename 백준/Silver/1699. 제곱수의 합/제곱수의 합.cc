#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int n;
int dp[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<int> square;
	square.push_back(1);
	// 초기값 설정 
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <= n; i++){
		int jud = sqrt(i); jud *= jud;
		if(jud == i){
			dp[i] = 1;
			square.push_back(i);
		}
		else{
			dp[i] = dp[1] + dp[i-1]; // square[0] 값 
			for(int x : square){
				dp[i] = min(dp[i], dp[x] + dp[i - x]);
			}
		}
	}
	cout << dp[n] << '\n';
}
