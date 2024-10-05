#include <iostream>
using namespace std;
int d[1002][1002];
int mod = 10007;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// iCj = i-1Cj + i-1Cj-1
	for(int i = 1; i <= 1000; i++){
		d[i][0] = d[i][i] = 1;
		for(int j = 1; j < i; j++){
			d[i][j] = (d[i-1][j] + d[i-1][j-1]) % mod;
		}
	}
	int n, m;
	cin >> n >> m;
	cout << d[n][m];
}
