#include <iostream>
using namespace std;

int DP[1005];
int mod = 10007;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	DP[1] = 1;
	DP[2] = 2;
	for(int i = 3; i <= n; i++){
		DP[i] = (DP[i-1]+DP[i-2])%mod;
	}
	cout << DP[n];
}
