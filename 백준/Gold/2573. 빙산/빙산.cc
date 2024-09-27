#include <iostream>
#include <queue>
#include <utility>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define X first
#define Y second

using namespace std;
queue<pair<int,int>> Q;

int map[303][303];
int vis[303][303];
int mlt_vis[303][303];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, year;

void cnt_bfs(pair<int,int> p){
	vis[p.X][p.Y] = year + 1;
	Q.push(p);
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( map[nx][ny] <= 0 || vis[nx][ny] >= year+1 ) continue;
			vis[nx][ny] = year + 1;
			Q.push({nx,ny});
		}
	}
}
void bfs(pair<int,int> p){
	mlt_vis[p.X][p.Y] = year + 1;
	Q.push(p);
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(map[nx][ny] <= 0 && vis[nx][ny] != year+1 ){
				if(map[cur.X][cur.Y] > 0 ) map[cur.X][cur.Y]--;
				continue;
			}
			if(mlt_vis[nx][ny] >= year+1) continue;
			mlt_vis[nx][ny] = year + 1;
			Q.push({nx,ny});
		}
	}
}
int main(){
	fastio;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	int ice_mnt;
	bool div_mnt;
	while(1){
		div_mnt = false;
		ice_mnt = 0; 
		for(int i = 1; i < N-1; i++){
			for(int j = 1; j < M-1; j++){
				if(map[i][j] > 0 && vis[i][j] == year){
					div_mnt = true;
					ice_mnt++;
					cnt_bfs({i,j});
					bfs({i,j});
				}
			}
		}
		if(ice_mnt >= 2 && div_mnt){
			cout << year; break;
		}
		else if(!div_mnt){
			cout << 0; break;
		}
		year++;	
	}
	
}