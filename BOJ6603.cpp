#include <iostream>
#include <algorithm>

using namespace std;
bool isUsed[52];
int res[7];
int num[15];
int k;
void func(int cur, int idx){
	if( cur == 6 ){
		for(int i = 0; i < 6; i++) cout << res[i] << ' ';
		cout << '\n';
		return;
	}
	for(int i = idx; i < k; i++){
		if(!isUsed[num[i]]){
			isUsed[num[i]] = true;
			res[cur] = num[i];
			func(cur+1, i);
			isUsed[num[i]] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true){
		cin >> k;
		if( k == 0 ) break;
		for(int i = 0; i < k; i++ ) cin >> num[i];
		sort(num, num+k);
		func(0, 0);
		cout << '\n';
	}
}
