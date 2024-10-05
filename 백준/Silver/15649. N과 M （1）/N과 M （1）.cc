#include <iostream>

using namespace std;

bool issu[10];
int arr[10];
int n, m;

void func(int k){
	if( k == m ){
		for(int i = 0; i < m; i++ ){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i = 1; i <= n; i++ ){
		if(!issu[i]){
			arr[k] = i;
			issu[i] = true;
			func(k+1);
			issu[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	func(0);
}