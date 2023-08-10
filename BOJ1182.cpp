#include <iostream>
using namespace std;

int arr[23];
int n, s;
int res = 0;
void func(int cur, int total){
	if( cur == n ){
		if(total == s) res++;
		return;
	}
	func(cur+1, total);
	func(cur+1, total+arr[cur]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	for(int i = 0; i < n; i++ ) cin >> arr[i];
	func(0, 0);
	if( s == 0 ) cout << res-1; else cout << res;
}
