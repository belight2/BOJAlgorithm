#include <iostream>
#include <queue>
#define X first
#define Y second
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
const int MX = 100002;
int map[MX];
int vis[MX];
int dx[2] = { 1, -1 };
int tpt = 2;
queue<int> Q;
void BFS(){
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		if( 2*cur <= MX ){
				if(vis[2*cur] == 0 || vis[2*cur] > vis[cur] ){
					Q.push(2*cur);
					vis[2*cur] = vis[cur];
				}
			}
		for(int i = 0; i < 2; i++){
			int nx = cur - dx[i];
			if( nx >= MX || nx < 0 ) continue;
			if( vis[nx] != 0 && vis[nx] <= vis[cur] ) continue;
			vis[nx] = vis[cur] + 1;
			Q.push(nx);
			
		}
	}
}
int main(){
	fastio;
	int n, k;
	cin >> n >> k;
	if( k < n) cout << n - k;
	else if( k == n ) cout << 0;
	else{
		Q.push(n);
		vis[n] = 1;
		if( 2 * n < MX ){
			Q.push( 2*n );
			vis[2*n] = 1;
		}
		BFS();
		cout << vis[k]-1;
	}
	
}