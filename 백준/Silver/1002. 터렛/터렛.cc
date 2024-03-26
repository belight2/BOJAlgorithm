#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, fx, fy, fr, sx, sy, sr, outR;
	double d, inR;
	
	cin >> T;
	for( int i = 0; i < T; i++ )
	{
		cin >> fx >> fy >> fr >> sx >> sy >> sr;
		d = sqrt( pow( fx - sx, 2 ) + pow( fy-sy, 2 ) );
		outR = fr + sr;
		inR = abs(fr - sr);
		
		if ( d == 0 )
		{
			if ( fr == sr )
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
		{
			if ( d > outR )
			{
				cout << 0 << "\n";
			}
			else if ( d == outR )
			{
				cout << 1 << "\n";
			}
			else if ( inR < d && d < outR )
			{
				cout << 2 << "\n";
			}
			else if ( d == inR )
			{
				cout << 1 << "\n";
			}
			else if ( d < inR )
			{
				cout << 0 << "\n";
			}
		}
	}
}