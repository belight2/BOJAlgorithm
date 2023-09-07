#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[304];
int DP[304][2];
int res;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	//DP
	DP[1][0] = arr[1];
	DP[2][0] = arr[2];
	DP[2][1] = arr[1] + arr[2];
	for(int idx = 3; idx <= n; idx++){
		DP[idx][0] = max(DP[idx-2][0], DP[idx-2][1]) + arr[idx];
		DP[idx][1] = DP[idx-1][0] + arr[idx];
	}
	res = max(DP[n][0], DP[n][1]);
	cout << res;
}

