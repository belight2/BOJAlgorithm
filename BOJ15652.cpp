#include <iostream>
using namespace std;

int arr[10];
int n, m;

void func(int k, int state){
	if( k == m ){
		for(int i = 0; i < m; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int x = state; x <= n; x++){
		arr[k] = x;
		func(k+1, x);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(0, 1);
}
