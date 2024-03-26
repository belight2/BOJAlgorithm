#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> res;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 1; i < 1024; i++){
		int b = i;
		ll num = 0;
		for(int j = 9; j >= 0; j--){
			if(b&1) num = 10*num + j;
			b /= 2;
		}
		res.push_back(num);
	}
	sort(res.begin(), res.end());
	int n ;
	cin >> n;
	if( n > 1022) cout << -1;
	else cout << res[n];
}
