#include <iostream>
#include <algorithm>
using namespace std;
int t[503][503];
int DP[503][503];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			cin >> t[i][j];
	DP[1][1] = t[1][1];
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			DP[i][j] = max(DP[i-1][j], DP[i-1][j-1]) + t[i][j];
		}
	}
	cout << *max_element(DP[n]+1, DP[n]+n+1);
}
