#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int R, G, B;
	int box = 0;
	
	cin >> R >> G >> B;
	
	int m = min(R, min(G, B));
	box += m;
	R -= m;
	G -= m;
	B -= m;
	
	box += R/3 + G/3 + B/3;
	R = R % 3;
	G = G % 3;
	B = B % 3;
	
	if( R == 0 )
	{
		if ( ( G > 0 ) and ( B > 0 ) ){
			if (G == 1 and B == 1){
				box += 1;
			}
			else{
				box += 2;
			}
		}
		else if ( ( G > 0 and B == 0 ) or ( B > 0 and G == 0 ) ){
			box += 1;
		}
	}
	else if( G == 0 )
	{
		if ( R > 0 and B > 0 ){
			if ( R == 1 and B == 1 ){
				box += 1;
			}
			else{
				box += 2;
			}
		}
		else if ( ( R > 0 and B == 0 ) or ( B > 0 and R == 0 ) ){
			box += 1;
		}
	}
	else if( B == 0 )
	{
		if ( G > 0 and R > 0 ){
			if ( G == 1 and R == 1 ){
				box += 1;
			}
			else{
				box += 2;
			}
		}
		else if ( ( G > 0 and R == 0 ) or ( R > 0 and G == 0 ) ){
			box += 1;
		}
	}
	
	cout << box << "\n";
		
}