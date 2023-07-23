#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second

using namespace std;

int map[51][51];
int vis[51][51];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};
int t, n, m, k;
int bug;
queue<pair<int, int>> Q;
void BFS(int x, int y){
	vis[x][y] = 1;
	Q.push({x,y});
	while(!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
			if( map[nx][ny] == 0 || vis[nx][ny] > 0 ) continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--){
		bug = 0;
		int x, y;
		cin >> n >> m >> k;
		
		for(int i = 0; i < n; i++){
			fill(map[i], map[i]+m, 0);
			fill(vis[i], vis[i]+m, 0);
		}
		
		for(int i = 0; i < k; i++){
			cin >> x >> y;
			map[x][y] = 1;
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(map[i][j] == 1 && vis[i][j] == 0){
					bug++;
					BFS(i,j);
				}
			}
		}
		cout << bug << '\n';
	}
}
