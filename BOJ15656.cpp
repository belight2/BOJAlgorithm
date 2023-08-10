#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int num[10];
int n, m;
void func(int k){
	if( k == m ){
		for(int i = 0; i < m; i++ ) cout << arr[i] << ' ';
		cout << '\n'; return;
	}
	for(int i = 0; i < n; i++ ){
		arr[k] = num[i];
		func(k+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++ ) cin >> num[i];
	sort(num, num+n);
	func(0);
}
