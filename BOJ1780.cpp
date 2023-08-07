#include <iostream>

using namespace std;
int map[2200][2200];
int res[3];
//���̰� �� ���ڷ� �����ϴ��� Ȯ�� 
bool check(int x, int y, int n){
	for(int i = x; i < x+n; i++)
		for(int j = y; j < y+n; j++)
			if( map[x][y] != map[i][j] )
				return false;
	return true;
}
//������ ������ ���� ��� �Լ�
void func(int x, int y, int n){
	if(check(x,y,n)){
		res[map[x][y]+1]++;
		return;
	}
	int slice = n / 3;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			func( x+i*slice, y+j*slice, slice );
		}
	}
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	func(0, 0, n);
	for(int x : res) cout << x << '\n';
}
