#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int nums[10];
bool isUsed[10];
int n, m;
void func(int k){
	if( k == m ){
		for(int i = 0; i < m; i++ ) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for(int i = 0; i < n; i++){
		if(!isUsed[i]){
			arr[k] = nums[i];
			isUsed[i] = true;
			func(k+1);
			isUsed[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(nums, nums+n);
	func(0);
}