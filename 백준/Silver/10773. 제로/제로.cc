#include <iostream>
#include <stack>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> stk;
	unsigned int res = 0;
	int t, x;
	cin >> t;
	while(t--){
		cin >> x;
		if( x == 0 && !stk.empty() ) stk.pop();
		else stk.push(x);
	}
	while(!stk.empty()){
		res += stk.top();
		stk.pop();
	}
	cout << res;
}