#include <iostream>
using namespace std;
long long DP[91];
int n;
long long S;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	DP[1] = 1; DP[2] = 1;
	S = DP[1];
	for(int i = 3; i <=n; i++){
		DP[i] = S + 1;
		S = S + DP[i-1];
	}
	cout << DP[n];
}
