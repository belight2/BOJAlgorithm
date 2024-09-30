#include <iostream>

using namespace std;
char map[66][66];
bool check(int x, int y, int n){
	for(int i = x; i < x + n; i++ )
		for(int j = y; j < y+n; j++ )
			if(map[x][y] != map[i][j])
				return false;
	return true;
}
void func(int x, int y, int n){
	if(check(x,y,n)){
		cout << map[x][y];
		return;
	}
	if( n >= 2 ) cout << '(';
	int slice = n / 2;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			func(x+i*slice, y+j*slice, slice);
		}
	}
	if( n >= 2 ) cout << ')';	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string str;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		for(int j = 0; j < n; j++)
			map[i][j] = str[j];
	}
	func(0,0,n);
}