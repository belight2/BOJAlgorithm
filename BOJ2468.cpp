#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#define X first
#define Y second

using namespace std;
int n, x;
int hgt[103][103];
int vis[103][103];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int maxH;
int maxCnt, cnt;
queue<pair<int,int>> Q;

void BFS(int h){
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
			if( hgt[nx][ny] <= h || vis[nx][ny] > 0 ) continue;
			vis[nx][ny]++;
			Q.push({nx,ny});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < n; j++){
			cin >> x;
			maxH = max(maxH, x);
			hgt[i][j] = x;
		}
	}
	for(int h = 0; h < maxH; h++){
		
		for(int i = 0; i < n; i++ ) fill(vis[i], vis[i]+n, 0);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if( hgt[i][j] > h && vis[i][j] == 0 ){
					cnt++;
					vis[i][j]++;
					Q.push({i,j});
					BFS(h);
				}
			}
		}
		maxCnt = max(maxCnt, cnt);
		cnt = 0;
	}
	cout << maxCnt ;
}
