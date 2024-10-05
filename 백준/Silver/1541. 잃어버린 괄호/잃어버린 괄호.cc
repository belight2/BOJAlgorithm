#include <iostream>
using namespace std;
int tmp, ans;
int sign = 1;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	cin >> input;
	for(char c : input){
		if( c == '+' || c == '-'){
			ans += tmp * sign;
			if( c == '-') sign = -1;
			tmp = 0;
		}
		else{
			tmp *= 10;
			tmp += c - '0';
		}
	}
	ans += tmp * sign;
	cout << ans;
}
