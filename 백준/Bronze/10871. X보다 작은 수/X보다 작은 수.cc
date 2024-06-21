#include<iostream>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a, x;
	cin >> a >> x;
	int n[a];
	
	for(int i = 0; i < a; i++) cin >> n[i];
	
	for( int i = 0; i < a; i ++) if( n[i] < x ) cout << n[i] << ' ';
}