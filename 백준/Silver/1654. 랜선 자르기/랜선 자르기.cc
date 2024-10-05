#include <iostream>
#define ll long long
using namespace std;

int k, n;
int a[10005];
bool solve(ll m){
	ll cur = 0;
	for(int i = 0; i < k; i++) cur += a[i] / m;
	return cur >= n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k >> n;
	for(int i = 0; i < k; i++) cin >> a[i];
	ll st = 1;
	ll en = 0x7fffffff;
	while(st < en){
		ll mid = (st+en+1) / 2;
		if(solve(mid)) st = mid;
		else en = mid-1;
	}
	cout << st;
}
