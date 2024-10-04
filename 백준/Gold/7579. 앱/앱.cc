#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cst[105]; // 각 앱의 cost
int mem[105]; // 각 앱의 memory 
int dp[105][10005]; // dp 테이블 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int c_sum = 0;
	for(int i = 1; i <= N; i++) cin >> mem[i];
	for(int i = 1; i <= N; i++){
		cin >> cst[i];
		c_sum += cst[i];
	}
	
	int res = c_sum;
	for(int c = 0; c <= c_sum; c++){
		for(int i = 1; i <= N; i++){
			if( cst[i] <= c ){
				dp[i][c] = max(dp[i-1][c - cst[i]] + mem[i], dp[i-1][c]);
			}
			else dp[i][c] = dp[i-1][c];
		}
	}
	for(int c = 0; c <= c_sum; c++){
		if(dp[N][c] >= M) res = min(res, c); 
	}
	cout << res;
}
