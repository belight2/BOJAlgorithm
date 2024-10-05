#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second

using namespace std;
long long ans;
pair<int,int> arr[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i].X >> arr[i].Y;
	sort(arr, arr+n);
	int firX = arr[0].X;
	int lasY = arr[0].Y;
	pair<int,int> cur;
	for(int i = 1; i < n; i++){
		cur = arr[i];
		if(cur.X <= lasY) lasY = max(lasY, cur.Y);
		else{
			ans += lasY - firX;
			firX = cur.X; lasY = cur.Y;
		}
	}
	ans += lasY-firX;
	cout << ans;
	
}
