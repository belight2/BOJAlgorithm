#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second

using namespace std;

bool isused[105];
int arr[105];
int ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i++) cin >> arr[i];
	int cnt = 0;
	for(int i = 1; i <= k; i++){
		if(isused[arr[i]]) continue;
		
		if(cnt < n){
			isused[arr[i]] = true;
			cnt++;
		}
		else{
			vector<pair<int,int>> idx;
			for(int x = 1; x <= k; x++){
				if(!isused[x]) continue;
				bool vis = false;
				for(int y = i + 1; y <= k; y++ ){
					if( x == arr[y] ){
						idx.push_back({y, x});
						vis = true;
						break;
					}
				}
				if(!vis) idx.push_back({ k+1, x });
			}
			sort(idx.rbegin(), idx.rend());
			int t = idx[0].Y;
			isused[t] = false;
			isused[arr[i]] = true;
			ans++;
		}
	}
	cout << ans;
}
