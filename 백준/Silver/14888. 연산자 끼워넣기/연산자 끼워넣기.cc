#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int n;
int arr[12];
deque<int> Q;
int oper[12];
int cnt[4];
int isused[4];
int res_min = 1000000000;
int res_max = -1000000000;

void solve(){
	int idx = 0;
	for(int i = 0; i < n; i++){
		Q.push_back(arr[i]);
	}
	while(true){
		if(idx == n-1){
			int res = Q.front(); Q.pop_front();
			res_min = min( res_min, res );
			res_max = max( res_max, res );
			break;
		}
		int x = Q.front(); Q.pop_front();
		int y = Q.front(); Q.pop_front();
		if( oper[idx] == 0 ){
			Q.push_front(x+y);
		}
		else if(oper[idx] == 1){
			Q.push_front(x-y);
		}
		else if(oper[idx] == 2){
			Q.push_front(x*y);
		}
		else if(oper[idx] == 3){
			Q.push_front(x/y);
		}
		idx++;
	}
}
void decide_op(int k){
	if( k == n-1 ){
		solve();
		return;
	}
	for(int i = 0; i < 4; i++){
		if(isused[i] < cnt[i] ){
			isused[i]++;
			oper[k] = i;
			decide_op(k+1);
			isused[i]--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++ ){
		cin >> arr[i];
	}
	for(int i = 0; i < 4; i++) cin >> cnt[i];
	decide_op(0);
	cout << res_max << '\n' << res_min;
}
