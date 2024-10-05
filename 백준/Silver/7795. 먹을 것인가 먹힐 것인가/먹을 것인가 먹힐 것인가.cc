#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define X first
#define Y second

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<pair<int,int>> arr(n+m);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			arr[i] = { x, 0 };
		}
		for(int i = n; i < n+m; i++){
			int x;
			cin >> x;
			arr[i] = { x, 1 };
		}
		sort(arr.begin(), arr.end());
		int res = 0; int cnt = 0;
		for(auto x : arr){
			if(x.Y == 0) res += cnt;
			else cnt++;
		}
		cout << res << '\n';
	}
}
