#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> stk;
string s;
int res, n = 1;
void solve(){
	char c;
	for(int i = 0; i < s.length(); i++){
		c = s[i];
		if(c == '('){
			n *= 2;
			stk.push(c);
		}
		else if(c == '['){
			n *= 3;
			stk.push(c);
		}
		else if( c == ')' ){
			if( stk.empty() || stk.top() != '('){
				cout << 0;
				return;
			}
			stk.pop();
			if( s[i-1] == '(') res += n;
			n /= 2; 
		}
		else if( c == ']'){
			if(stk.empty() || stk.top() != '['){
				cout << 0;
				return;
			}
			stk.pop();
			if(s[i-1] == '[') res += n;
			n /= 3;
		}
	}
	if(!stk.empty()){
		cout << 0;
		return;
	}
	cout << res;
}
int main(){
	cin >> s;
	solve();
}