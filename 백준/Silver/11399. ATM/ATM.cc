#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr, arr+n+1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		arr[i] += arr[i-1];
		ans += arr[i]; 
	} 
	cout << ans;
}
