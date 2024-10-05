#include <iostream>
#include <algorithm>
using namespace std;
int DP[1000006];
int root[1000006];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	DP[1] = 0; DP[2] = 1; DP[3] = 1;
	root[1] = 0; root[2] = 1; root[3] = 1;
	for(int i = 4; i <= n; i++){
		int tmp;
		DP[i] = DP[i-1]+1;
		root[i] = i-1;
		tmp = DP[i];
		if(i%2 == 0){
			DP[i] = min(DP[i/2]+1, DP[i]);
			if(tmp != DP[i] ){
				root[i] = i/2;
			}
			tmp = DP[i];
		}
		if(i%3 == 0){
			DP[i] = min(DP[i/3]+1, DP[i]);
			if(tmp != DP[i]) root[i] = i/3;
		}
	}
	cout << DP[n] << '\n';
	int cur = n;
	while(cur >= 1){
		cout << cur << ' ';
		cur = root[cur];
	}
}