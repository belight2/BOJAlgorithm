#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	while(1){
		stack<char> stk;
		getline(cin, s);
		if(s == ".") break;
		bool res = true;
		for(auto c : s){
			if( c == '(' || c == '[') stk.push(c);
			else if( c == ')'){
				if(stk.empty() || stk.top() != '('){
					res = false;
					break;
				}
				stk.pop();
			}
			else if( c == ']'){
				if(stk.empty() || stk.top() != '['){
					res = false;
					break;
				}
				stk.pop();
			}
		}
		if(!stk.empty()) res = false;

		if(res) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
}