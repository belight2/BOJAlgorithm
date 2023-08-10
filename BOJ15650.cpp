#include <iostream>
using namespace std;

bool isUsing[10];
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
	for(int x = state; x <= n; x++ ){
		if(!isUsing[x]){
			arr[k] = x;
			isUsing[x] = true;
			func(k+1, x);
			isUsing[x] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(0, 1);
}
