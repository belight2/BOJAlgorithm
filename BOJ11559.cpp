#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second

using namespace std;

char field[15][8];
int vis[15][8];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int,int>> Q;
int res = 0;
int n = 12, m = 6;


void fallPuyo(){
	for(int col = 0; col < m; col++){
		int idx = n-1;
		for(int row = n-1; row >= 0; row-- ){
			if(field[row][col] == '.') continue;
			field[idx][col] = field[row][col];
			idx--;
		}
		for(int row = idx; row >= 0; row--) field[row][col] = '.';
	}
}
// color는 찾으려는 뿌요의 색
// mode = -1 이면 flood_fill
// mode = 1 이면 뿌요를 터뜨리는 것 
int BFS(int x, int y, char color, int mode){
	int area = 1;
	Q.push({x,y});
	vis[x][y] *= -1;
	if( mode == 1 ) field[x][y] = '.';
	while(!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
			if( field[nx][ny] != color || vis[nx][ny] != mode ) continue;
			vis[nx][ny] *= -1;
			if( mode == 1 ) field[nx][ny] = '.';
			else area++;
			Q.push({nx,ny});
		}
	}
	return area;
}
int main(){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++ )
			cin >> field[i][j];		
	bool isBomb = false;
	while(true){
		for(int i = 0; i < n; i++) fill(vis[i], vis[i]+m, -1 );
		for(int row = n - 1; row >= 0; row-- ){
			for(int col = 0; col < m; col++ ){
				if(field[row][col] == '.' || vis[row][col] != -1) continue;
				char color = field[row][col];
				int area = BFS(row,col,color, -1);
				if( area >= 4){
					isBomb = true;
					BFS(row,col,color,1);
				}
			}
		}
		if(!isBomb){
			break;
		}
		else{
			isBomb = false;
			res++;
		}
		fallPuyo();
	}
	cout << res;	
}
