#include <iostream>
using namespace std;
int a, b, c;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true){
		cin >> a >> b >> c;
		if(a==0&&b==0&&c==0) break;
		int x, y, z;
		x = a * a; y = b * b; z = c * c;
		if(x == y+z) cout << "right\n";
		else if(y == x + z) cout << "right\n";
		else if( z == x+y) cout << "right\n";
		else cout << "wrong\n";
	}
}