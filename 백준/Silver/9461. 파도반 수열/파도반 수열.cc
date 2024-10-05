#include <iostream>
using namespace std;
long long P[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 }; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	for(int idx = 11; idx <= 100; idx++) P[idx] = P[idx-1] + P[idx-5];
	while(t-->0){
		cin >> n;
		cout << P[n] << '\n';
	}	
}
