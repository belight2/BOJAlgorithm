#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1005][1005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	int len_a = a.length();
	int len_b = b.length();
	// 초기값 설정
	for(int i = 0; i <= len_a; i++){
		dp[i][0] = i; // 삭제연산  
	} 
	for(int j = 0; j <= len_b; j++){
		dp[0][j] = j; //삽입 연산 
	}
	
	for(int i = 1; i <= len_a; i++){
		for(int j = 1; j <= len_b; j++){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1 + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
			}
		}
	}
	cout << dp[len_a][len_b];
}
