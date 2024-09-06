#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	stack<char> stk;
	int res = 0;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(') stk.push(s[i]);
		else{
			if( s[i-1] == '(') res += stk.size()-1;
			else res++;
			stk.pop();
		}
	}
	cout << res;
}