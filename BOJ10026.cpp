#include <iostream>
#include <queue>
#include <utility>
#include <string>
#define X first
#define Y second
using namespace std;

int n;
queue<pair<int,int>> Q;
int reg_vis[101][101];
int rng_vis[101][101];
char map[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string s;
int res[2];

void REG_bfs(char c, int x, int y){	
	reg_vis[x][y] = 1;
	Q.push({x,y});
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
			if( c == 'B'){
				if( map[nx][ny] != c || reg_vis[nx][ny] > 0 ) continue;
			}
			else{
				if( map[nx][ny] == 'B' || reg_vis[nx][ny] > 0 ) continue;
			}
			reg_vis[nx][ny] = 1;
			Q.push({nx,ny});
		}
	}	
}
void RNG_bfs(char c, int x, int y){
	
	rng_vis[x][y] = 1;
	Q.push({x,y});
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
			if( map[nx][ny] != c || rng_vis[nx][ny] > 0 ) continue;
			rng_vis[nx][ny] = 1;
			Q.push({nx,ny});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			map[i][j] = s[j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if( reg_vis[i][j] == 0 ){
				res[0]++;
				REG_bfs(map[i][j], i, j);
			}
			if( rng_vis[i][j] == 0){
				res[1]++;
				RNG_bfs(map[i][j], i, j);
			}
		}
	}
	cout << res[1] << ' ' << res[0];	
}
