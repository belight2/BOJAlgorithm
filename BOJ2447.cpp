#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
char map[6562][6562];
void full(int x, int y, int n){
	for(int i = x; i < x + n; i++ ){
		for(int j = y; j < y+n; j++ ){
			map[i][j] = ' ';
		}
	}
}
void Print(int x, int y, int n, bool isBlank){
	if(isBlank){
		full(x,y,n);
		return;
	}
	if(n==1) return;
	int slice = n / 3;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if( i == 1 && j == 1 ) Print(x+i*slice, y+j*slice, slice, true);
			else Print(x+i*slice, y+j*slice, slice, false);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) fill(map[i], map[i]+n, '*');
	Print(0,0,n,false);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
}
