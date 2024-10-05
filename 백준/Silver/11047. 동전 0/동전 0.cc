#include <iostream>
using namespace std;
int n, k;
int arr[15];
int res;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	for(int i = n-1; i >= 0; i--){
		res += k / arr[i];
		k = k % arr[i];
	}
	cout << res;
}
