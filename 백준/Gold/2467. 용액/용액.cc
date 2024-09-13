#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans1 = 1e9+1;
	int ans2 = 1e9+1;
	for(int i = 0; i < n; i++){
		int idx = lower_bound(a, a+n, -a[i]) - a;
		if(idx != 0 && idx-1 != i && abs(a[i] + a[idx-1]) < abs(ans1+ans2)){
			ans1 = a[i];
			ans2 = a[idx-1];
		}
		if(idx < n && idx != i && abs(a[i] + a[idx]) < abs(ans1 + ans2)){
			ans1 = a[i];
			ans2 = a[idx];
		}
		if(idx+1 < n && idx+1 != i && abs(a[i] + a[idx+1]) < abs(ans1+ans2)){
			ans1 = a[i];
			ans2 = a[idx+1];
		}
	}
	if(ans1 > ans2) swap(ans1, ans2);
	cout << ans1 << ' ' << ans2;
}
