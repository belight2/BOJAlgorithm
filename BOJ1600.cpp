#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#define X first
#define Y second

using namespace std;

int map[203][203];
int vis[203][203][32];
int Hx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int Hy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<tuple<int,int,int>> Q;
int W,H,K;
void bfs(){
	Q.push(make_tuple(0,0,0));
	vis[0][0][0] = 1;
	while(!Q.empty()){
		int curX, curY, cntMoving;
		tie(curX, curY, cntMoving)= Q.front(); Q.pop();
		if( K > cntMoving ){
			for(int dir = 0; dir < 8; dir++){
				int nx = curX + Hx[dir];
				int ny = curY + Hy[dir];
				if( nx < 0 || nx >= H || ny < 0 || ny >= W ) continue;
				if(map[nx][ny] == 1) continue;
				if(vis[nx][ny][cntMoving+1] != 0 && vis[nx][ny][cntMoving+1] <= vis[curX][curY][cntMoving] + 1 ) continue;
				Q.push(make_tuple(nx,ny,cntMoving+1));
				vis[nx][ny][cntMoving+1] = vis[curX][curY][cntMoving] + 1;
			}
		}
		for(int dir = 0; dir < 4; dir++){
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if( nx < 0 || nx >= H || ny < 0 || ny >= W ) continue;
			if(map[nx][ny] == 1) continue;
			if(vis[nx][ny][cntMoving] != 0 ) continue;
			Q.push(make_tuple(nx,ny,cntMoving));
			vis[nx][ny][cntMoving] = vis[curX][curY][cntMoving] + 1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K;
	cin >> W >> H;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> map[i][j];
		}
	}
	bfs();
	int res = 10000000;
	bool success = false;
	for(int idx = 0; idx <= K; idx++){
		if( vis[H-1][W-1][idx] != 0 && vis[H-1][W-1][idx] < res ){
			success = true;
			res = vis[H-1][W-1][idx];
		}
	}
	if(success) cout << res-1;
	else cout << -1;
}
