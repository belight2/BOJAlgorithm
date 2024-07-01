#include <iostream>
#include <stack>
using namespace std;

char res[1000001];
int arr[1000001], pos = 0 ,cur = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	stack<int> stk;
	cin >> t;
	
	for(int i = 0; i< t; i++){
		cin >> n;
		arr[i] = n;
	}
	
	for(int i = 1; i <= t; i++){
		stk.push(i);
		res[cur++] = '+';
		while( stk.top() == arr[pos] ){
			res[cur++] = '-';
			stk.pop();
			pos++;
			if(stk.empty()) break;
		}
	}
	
	if( cur == 2*t){
		for(int i = 0; i < cur; i++) cout << res[i] << '\n';
	}
	else cout << "NO";	
}