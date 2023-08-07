#include <iostream>

using namespace std;

int map[129][129];
int res[2];

bool check(int x, int y, int n){
	for(int i = x; i < x+n; i++)
		for(int j = y; j < y+n; j++)
			if(map[x][y] != map[i][j] )
				return false;
	return true;
}
void func(int x, int y, int n){
	if(check(x,y,n)){
		res[map[x][y]]++;
		return;
	}
	int slice = n / 2;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			func(x+i*slice, y+j*slice,slice);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
	func(0,0,n);
	for(int x : res ) cout << x << '\n';
}
