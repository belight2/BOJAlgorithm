#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int num[10];
int isUsed[10];
int n, m;
void func(int k, int idx){
	if( k == m ){
		for(int i = 0; i < m; i++ ) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for(int i = idx; i < n; i++ ){
		if(!isUsed[i]){
			arr[k] = num[i];
			isUsed[i] = true;
			func(k+1, i);
			isUsed[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++ ) cin >> num[i];
	sort(num, num+n);
	func(0, 0);
}
