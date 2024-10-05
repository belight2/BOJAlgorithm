#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> arr;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		arr.push_back(x);
	}
	sort(arr.rbegin(), arr.rend());
	int res = 0;
	for(int k = 1; k <= n; k++){
		res = max(res, arr[k-1]*k);
	}
	cout << res;
}
