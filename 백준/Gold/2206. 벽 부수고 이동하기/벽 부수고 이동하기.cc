#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#define X first
#define Y second
using namespace std;

char map[1001][1001];
int dist[1001][1001][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<tuple<int,int,int>> Q;
int N, M;

void BFS(){
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	Q.push(make_tuple(0,0,0));
	while(!Q.empty()){
		int curX, curY, broken;
		tie(curX, curY, broken) = Q.front();
		if(curX == N-1 && curY == M-1 ){
			cout << dist[curX][curY][broken];
			return;
		} 
		Q.pop();
		int nxtDist = dist[curX][curY][broken]+1;
		for(int dir = 0; dir < 4; dir++ ){
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if( nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
			if(dist[nx][ny][broken] == 0 && map[nx][ny] == '0'){
				dist[nx][ny][broken] = nxtDist;
				Q.push(make_tuple(nx,ny,broken));
			}
			if( !broken && map[nx][ny] == '1' && dist[nx][ny][1] == 0 ){
				dist[nx][ny][1] = nxtDist;
				Q.push(make_tuple(nx,ny,1));
			}
		}
	}
	cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	BFS();
}