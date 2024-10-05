#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int DP[100001];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >>arr[i];
	DP[1] = arr[1];
	for(int i = 2; i <= n; i++){
		DP[i] = max(DP[i-1]+arr[i], arr[i]);
	}
	cout << *max_element(DP+1, DP+n+1);
}
