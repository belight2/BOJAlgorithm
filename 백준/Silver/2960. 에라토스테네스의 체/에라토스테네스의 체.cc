#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<bool> p(n+1, true);
	p[1] = false;
	for(int i = 2; i <= n; i++){
		if(!p[i]) continue;
		for(int j = i; j <= n; j+=i){
			if(!p[j]) continue;
			p[j] = false;
			if(--k == 0){
				cout << j;
				return 0;
			}
		}
	}
}
