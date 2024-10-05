#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	while(n){
		ans += n / 5;
		n /= 5;
	}
	cout << ans;
}