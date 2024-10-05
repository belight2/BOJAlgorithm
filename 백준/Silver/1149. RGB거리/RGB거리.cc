#include <iostream>
#include <algorithm>
using namespace std;

int S[1002][5];
int DP[1002][5];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> S[i][j];
		}
	}
	// 초기값 
	for(int i = 0; i < n; i++) DP[0][i] = S[0][i];
	//점화식
	for(int i = 1; i < n; i++){
		DP[i][0] = min(DP[i-1][1], DP[i-1][2]) + S[i][0];
		DP[i][1] = min(DP[i-1][0], DP[i-1][2]) + S[i][1];
		DP[i][2] = min(DP[i-1][0], DP[i-1][1]) + S[i][2];
	}
	int res = *min_element(DP[n-1], DP[n-1]+3);
	cout << res;
}
