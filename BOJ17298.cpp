#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#define X first
#define Y second

using namespace std;
int n, x;
stack<pair<int, int>> stk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> x;
	stk.push({x, 0});
	int res[n];
	fill(res, res+n, -1);
	for(int i = 1; i < n; i++){
		cin >> x;
		while( stk.top().X < x ){
			res[stk.top().Y] = x;
			stk.pop();
			if(stk.empty()) break;
		}
		stk.push({x,i});
	}
	for(int x : res) cout << x << ' ';
}
