#include <iostream>
#include <cmath>
using namespace std;
int n;
int ability[22][22];
bool isused[22];
int res = 100000000;
void solve(){
	int start[n/2], link[n/2];
	int i = 0; int j = 0;
	int start_ability = 0;
	int link_ability = 0;
	for(int idx = 0; idx < n; idx++){	
		if(isused[idx]){
			start[i++] = idx;
		}
		else link[j++] = idx;
	}
	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < n/2; j++){
			start_ability += ability[start[i]][start[j]];
			link_ability += ability[link[i]][link[j]];
		}
	}
	res = min( res, abs(start_ability - link_ability));
}
void decide_team(int k, int idx){
	if( k == n/2 ){
		solve();
		return;
	}
	for(int i = idx; i < n; i++){
		if(!isused[i]){
			isused[i] = true;
			decide_team(k+1, i);
			isused[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> ability[i][j];
		}
	}
	decide_team(0, 0);
	cout << res;
}
