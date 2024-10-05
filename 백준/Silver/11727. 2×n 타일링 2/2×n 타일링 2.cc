#include <iostream>
using namespace std;
int DP[1001];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	DP[1] = 1; DP[2] = 3;
	for(int i = 3; i <= n; i++){
		DP[i] = (DP[i-1] + (2 * DP[i-2])) % 10007;
	}
	cout << DP[n];
}
