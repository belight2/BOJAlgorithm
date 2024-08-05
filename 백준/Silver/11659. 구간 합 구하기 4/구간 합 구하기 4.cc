#include <iostream>
using namespace std;

int n;
int m;
int arr[100005], DP[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		DP[i] = DP[i-1] + arr[i]; //구간을 1부터 잡아서 가능 
	}
	while(m--){
		int i, j;
		cin >> i >> j;
		cout << DP[j] - DP[i-1] << '\n';
	}	
}
