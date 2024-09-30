#include <iostream>
using namespace std;
int find(int n, int r, int c){
	if( n == 0 ) return 0;
	int half = 1 << ( n - 1 );
	if( r < half && c < half ) return find( n - 1, r, c);
	else if( r < half && c >= half ) return half * half + find( n - 1, r, c - half);
	else if( r >= half && c < half ) return 2 * half * half + find( n - 1, r - half, c );
	else if( r >= half && c >= half ) return 3 * half * half + find( n - 1, r - half, c - half );
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, r, c;
	cin >> n >> r >> c;
	cout << find(n, r, c);
}