#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1004];
int DP[1004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		DP[i] = arr[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(arr[j] < arr[i]) DP[i] = max(DP[i],DP[j]+arr[i]);
		}
	}
	cout << *max_element(DP+1, DP+n+1);
}
