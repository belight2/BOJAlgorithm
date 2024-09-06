#include <iostream>
#include <stack>
#include <utility>

#define X first
#define Y second

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,h;
	stack< pair<int, int> > stk;
	stk.push( {100000001, 0} );
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> h;
		while(stk.top().X < h) stk.pop();
		cout << stk.top().Y << ' ';
		stk.push({h, i});
	}
}