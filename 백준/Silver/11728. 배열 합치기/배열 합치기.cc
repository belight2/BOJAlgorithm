#include <iostream>
using namespace std;
int a[1000005], b[1000005], c[2000010];
int n, m;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	int aidx = 0, bidx = 0;
	for(int i = 0; i < n+m; i++ ){
		if( aidx >= n ) c[i] = b[bidx++];
		else if( bidx >= m ) c[i] = a[aidx++];
		else if( a[aidx] > b[bidx] ) c[i] = b[bidx++];
		else c[i] = a[aidx++];
	}
	for(int i = 0; i < n+m; i++ ) cout << c[i] << ' ';
	
}
