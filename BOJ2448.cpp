#include <iostream>
#include <algorithm>
using namespace std;

char map[3074][6148];
void Print(int x, int y, int n){
	if( n == 3 ){
		map[x][y] = '*';
		map[x+1][y-1] = '*'; map[x+1][y+1] = '*'; 
		for(int i = y-2; i < y+3; i++) map[x+2][i] = '*';
		return;
	}
	int slice = n / 2;
	Print( x, y, slice );
	Print( x+slice, y - slice, slice);
	Print( x+slice, y + slice, slice);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) fill(map[i], map[i]+2*n, ' ');
	Print(0, n-1, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2*n-1; j++){
			cout << map[i][j];
		}
		cout << '\n';
	}
}
