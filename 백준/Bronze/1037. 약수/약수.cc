#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[52];
int res;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++ ) cin >> arr[i];
	sort(arr, arr+n);
	res = arr[0] * arr[n - 1];
	cout << res;
}