#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <tuple>
#define X first
#define Y second
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int map[102][102];
pair<int,int> vis[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<tuple<int,int,int>> Q;
vector<int> res;
int N;
int island = 1;

void flood_fill(){
	while(!Q.empty()){
		int curX, curY, state;
		tie( curX, curY, state ) = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++ ){
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
			if( map[nx][ny] == 0 || vis[nx][ny].X == -1 ) continue;
			vis[nx][ny] = { -1, state };
			Q.push(make_tuple(nx,ny,state));
		}
	}
}
bool isCoast(int x, int y){
	for(int dir = 0; dir < 4; dir++ ){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
		if(map[nx][ny] == 0 ) return true;
	}
	return false;
}
void dist_bfs(){
	while(!Q.empty()){
		int curX, curY, state;
		tie( curX, curY, state ) = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++ ){
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
			if(vis[nx][ny].X > 0 && vis[nx][ny].Y != state ){
				res.push_back(vis[nx][ny].X + vis[curX][curY].X);
				continue;
			}
			if( map[nx][ny] == 1 || (vis[nx][ny].X > 0 && vis[nx][ny].Y == state) ) continue;
			vis[nx][ny] = { vis[curX][curY].X + 1 , state };
			Q.push(make_tuple(nx,ny,state));
		}
	}
}
int main(){
	fastio;
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] == 1 && vis[i][j].X == 0){
				Q.push(make_tuple(i,j,island));
				vis[i][j] = { -1, island };
				flood_fill();
				island++;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(map[i][j] == 1 && isCoast(i,j)){
				Q.push(make_tuple(i,j,vis[i][j].Y));
				vis[i][j].X = 0;
			}
		}
	}
	
	dist_bfs();
	int ans = *min_element(res.begin(), res.end());
	cout << ans;
}
