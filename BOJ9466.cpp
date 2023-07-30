#include <iostream>
#include <algorithm>
using namespace std;

int vis[100002];
int map[100002];
int NOT_VISIT = 0;
int CYCLE = -1;
void isCycle(int x){
	int cur = x;
	vis[cur] = x;
	while(true){
		cur = map[cur];
		if( vis[cur] == x ){
			while(vis[cur] != CYCLE){
				vis[cur] = CYCLE;
				cur = map[cur];
			}
			return;
		}
		if( vis[cur] != NOT_VISIT) return;
		vis[cur] = x;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fill(vis, vis+n+1, 0);
		for(int i = 1; i <= n; i++){
			cin >> map[i];
		}
		for(int i = 1; i <= n; i++){
			if(vis[i] == NOT_VISIT) isCycle(i);
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i] != CYCLE ) cnt++;
		}
		cout << cnt << '\n';
		
	}
}
