#include <iostream>
#include <stack>
using namespace std;

void solve(){
	int n, x;
	long long ans = 0;
	stack<int> stk;
	cin >> n;
	while(n--){
		cin >> x;
		stk.push(x);
	}
	int mx_cur = stk.top();
	while(!stk.empty()){
		int cur = stk.top(); stk.pop();
		if(cur < mx_cur) ans += (mx_cur-cur);
		else mx_cur = cur;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) solve();
}
