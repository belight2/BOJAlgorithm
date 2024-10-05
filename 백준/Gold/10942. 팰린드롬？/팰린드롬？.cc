#include <iostream>
#include <fstream>
using namespace std;

int n, m, st, ed;
int s[2005];
int dp[2005][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	// 초기값 설정
	for(int i = 0; i < n; i++) dp[i][i] = 1; 
	//점화식 진행
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < i + 3; j++){
			if(s[i] == s[j]){
				dp[i][j] = 1;
				int l = i - 1; int r = j + 1;
				while( l >= 0 && r < n ){
					if(s[l] == s[r]){
						dp[l][r] = dp[l+1][r-1];
					}
					l--; r++;
				}
			}
		}
	}
	cin >> m;
	while(m--){
		cin >> st >> ed;
		cout << dp[st-1][ed-1] << '\n';
	}
}
