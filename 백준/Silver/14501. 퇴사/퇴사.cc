#include <iostream>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int n;
int DP[17];
bool isWork[17];
pair<int, int> arr[17];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fill(isWork+1, isWork+1+n, true);
	for(int i = 1; i <= n; i++){
		cin >> arr[i].X >> arr[i].Y;
		DP[i] = arr[i].Y;
		if(i + arr[i].X > n+1) isWork[i] = false;
	}
	for(int i = 1; i <= n; i++){
		for(int j = arr[i].X+i; j <= n; j++){
			if(isWork[j]) DP[j] = max(DP[j], DP[i]+arr[j].Y);
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(isWork[i]) res = max(res, DP[i]);
	}
	cout << res;
}
