#include <iostream>
using namespace std;

int map[10];
bool vali[9][9];
int n, m;

void func(int k){
	if( k == m ){
		for(int i = 0; i < m; i++){
			cout << map[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i = 1; i <= n; i++ ){
		if(!vali[i][k]){
			map[k] = i;
			vali[i][k] = true;
			func(k+1);
			vali[i][k] = false;
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