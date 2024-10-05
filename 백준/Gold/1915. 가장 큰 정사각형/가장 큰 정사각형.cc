#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int board[1005][1005];
int dp[1005][1005];
int ans = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			board[i][j] = s[j] - '0';
			ans = max(board[i][j], ans);
		}
	}
	// 초기값 설정  
	for(int i = 0; i < n; i++) dp[i][0] = board[i][0];
	for(int j = 0; j < m; j++) dp[0][j] = board[0][j];
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(board[i][j] == 1)
				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
				ans = max(ans, dp[i][j]);
		}
	}
	cout << ans * ans;
}
