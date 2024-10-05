#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#define X first
#define Y second

using namespace std;

int n, m;
int map[505][505];
bool vis[505][505];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int,int>> Q;

int BFS(int x, int y ){
	int area = 1; //그림의 크기 
	Q.push({x,y});
	vis[x][y] = true;
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
			if(vis[nx][ny] || map[nx][ny] != 1 ) continue;
			Q.push({nx,ny});
			area++; 
			vis[nx][ny] = true;
		}
	}
	return area;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < m; j++ ){
			cin >> map[i][j]; //그림 정보 입력 
		}
	}
	int area = 0; int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j] and map[i][j] == 1 ){
				area = max(area, BFS(i,j));
				cnt++;
			}
		}
	}
	cout << cnt << '\n' << area;
}
