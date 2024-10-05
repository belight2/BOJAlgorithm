#include <iostream>

using namespace std;

int res = 0;
int n;
bool isUsed1[16];
bool isUsed2[30];
bool isUsed3[30];
void func(int cur){
	if( cur == n ){
		res++; return;
	}
	for(int i = 0; i < n; i++){
		if(!isUsed1[i]&&!isUsed2[cur+i]&&!isUsed3[cur-i+n-1]){
			isUsed1[i] = true;
			isUsed2[cur+i] = true;
			isUsed3[cur-i+n-1] = true;
			func(cur+1);
			isUsed1[i] = false;
			isUsed2[cur+i] = false;
			isUsed3[cur-i+n-1] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	func(0);
	cout << res;
}