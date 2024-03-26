#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
//------------- 회전 횟수 --------------
int rot[5];
//--------------------------------------
//------------- 판 순서 ----------------
int seq[5];
int isused[5];
//--------------------------------------
//----------- 너비 우선 탐색 -----------
queue<tuple<int,int,int>> Q;
int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 1, 0, -1, 0, 0 };
//--------------------------------------
//------------ 그 외 변수 --------------
int maze[6][6][6];
int tmp[6][6][6];
int srch_maze[6][6][6];
int sz = 5;
const int MAX_VALUE = 900000000;
int res = MAX_VALUE;
//---------------------------------------
void bfs(){
	int dist[6][6][6];
	if(srch_maze[0][0][0] == 0 ) return;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++) fill(dist[i][j], dist[i][j]+sz, 0 );
	}
	Q.push(make_tuple(0,0,0));
	dist[0][0][0] = 1;
	while(!Q.empty()){
		int curX, curY, curZ;
		tie(curX, curY, curZ) = Q.front(); Q.pop();
		for(int dir = 0; dir < 6; dir++){
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if( nx < 0 || ny < 0 || nz < 0 || nx >= sz || ny >= sz || nz >= sz ) continue;
			if( srch_maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0 ) continue;
			Q.push(make_tuple(nx,ny,nz));
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
		}
	}
	if( dist[4][4][4]-1 != -1 ) res = min(res, dist[4][4][4]-1);
}
void rotation(int num){
	for(int row = 0; row < sz; row++){
		for(int col = 0; col < sz; col++){
			tmp[num][row][col] = srch_maze[num][row][col];
		}
	}
	for(int col = 0; col < sz; col++){
		for(int row = 0; row < sz; row++){
			srch_maze[num][row][col] = tmp[num][col][sz - row - 1];
		}
	}
}
void solve(){
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++ )
			for(int k = 0; k < sz; k++)
				srch_maze[i][j][k] = maze[seq[i]][j][k];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < rot[i]; j++ ){
			rotation(seq[i]);
		}
	}
	bfs();
}
void decide_sequence(int k){
	if( k == 5 ){
		solve();
		return;
	}
	for(int i = 0; i < 5; i++){
		if(!isused[i]){
			isused[i] = true;
			seq[k] = i;
			decide_sequence(k+1);
			isused[i] = false;
		}
	}
}
void decide_dir(int k){
	if( k == 5 ){
		decide_sequence(0);
		return;
	}
	for(int i = 0; i < 4; i++){
		rot[k] = i;
		decide_dir(k+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++ )
			for(int k = 0; k < sz; k++)
				cin >> maze[i][j][k];
	
	decide_dir(0);
	if( res == MAX_VALUE ) cout << -1;
	else cout << res;
}