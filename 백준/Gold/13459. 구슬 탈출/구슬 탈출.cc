#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second

using namespace std;

int n, m;
char board[11][11];
char board2[11][11];
pair<int, int> init_red, init_blue, Exit;
pair<int, int> red, blue;
queue<pair<int,int>> marble;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int diret[10];
int res = 11;

pair<int,int> move(int dir){
	board2[marble.front().X][marble.front().Y] = '.';
	while(true){
		pair<int,int> cur = marble.front(); marble.pop();
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(board2[nx][ny] == '#' || board2[nx][ny] == 'R' || board2[nx][ny] == 'B'){
			return {cur.X, cur.Y};
		}
		if(board2[nx][ny] == 'O') return {nx,ny};
		marble.push({nx,ny});
	}
}
void solve(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			board2[i][j] = board[i][j];
		}
	}
	red = { init_red.X, init_red.Y }; blue = { init_blue.X, init_blue.Y };
	bool red_success = false;
	bool blue_success = false;
	for(int i = 0; i < 10; i++){
		int r_x = red.X; int r_y = red.Y; int b_x = blue.X; int b_y = blue.Y;
		int dir = diret[i];
		if((dir == 0 && b_y > r_y) || (dir == 1 && b_x > r_x) || ( dir == 2 && b_y < r_y) || (dir == 3 && b_x < r_x)) {
			marble.push({b_x,b_y});
			blue = move(dir);
			if(board2[blue.X][blue.Y] == 'O') blue_success = true;
			else board2[blue.X][blue.Y] = 'B';
			
			marble.push({r_x,r_y});
			red = move(dir);
			if(board2[red.X][red.Y] == 'O') red_success = true;
			else board2[red.X][red.Y] = 'R';
		}
		else{
			marble.push({r_x,r_y});
			red = move(dir);
			if(board2[red.X][red.Y] == 'O') red_success = true;
			else board2[red.X][red.Y] = 'R';
			
			marble.push({b_x,b_y});
			blue = move(dir);
			if(board2[blue.X][blue.Y] == 'O') blue_success = true;
			else board2[blue.X][blue.Y] = 'B';
		}
		if(red_success&&!blue_success){
			res = min(res, i+1);
			return;
		}
		else if(blue_success){
			return;
		}
	}
	
}
void decide_dir(int k){
	if( k == 10 ){
		solve();
		return;
	}
	for(int i = 0; i < 4; i++ ){
		diret[k] = i;
		decide_dir(k+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			if(board[i][j] == 'R') init_red = { i, j };
			if(board[i][j] == 'B') init_blue = { i, j };
			if(board[i][j] == 'O') Exit = { i, j };
		}
	}
	decide_dir(0);
    cout << (res <= 10);
}