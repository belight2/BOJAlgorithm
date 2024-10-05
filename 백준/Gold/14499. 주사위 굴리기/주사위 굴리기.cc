#include <iostream>
#include <utility>
#define X first
#define Y second
using namespace std;
 
int top = 1;
int dice[7];
int side[4] = { 3, 4, 2, 5 };
 
int map[22][22];
int n, m;
pair<int,int> dicePos;
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int k;

void roll(int dir){
	int p_top = top;
	if( dir == 1 ){ 
		top = side[1];
		side[1] = 7 - p_top;
		side[0] = p_top;
	}
	else if( dir == 2 ){
		top = side[0];
		side[0] = 7 - p_top;
		side[1] = p_top;
	}
	else if( dir == 3 ){ 
		top = side[3];
		side[3] = 7 - p_top;
		side[2] = p_top;
	}
	else if( dir == 4 ){
		top = side[2];
		side[2] = 7 - p_top;
		side[3] = p_top;
	}
}
void BottomCheck(){
	int row = dicePos.X; int col = dicePos.Y;
	int btm = 7 - top;
	if( map[row][col] == 0 ) map[row][col] = dice[btm];
	else{
		dice[btm] = map[row][col]; map[row][col] = 0;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> dicePos.X >> dicePos.Y >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++ )
			cin >> map[i][j];
		
	while(k--){
		int dir;
		cin >> dir;
		int nx = dicePos.X + dx[dir];
		int ny = dicePos.Y + dy[dir];
		if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
		dicePos.X = nx; dicePos.Y = ny;
		roll(dir);
		cout << dice[top] << '\n';
		BottomCheck();
	} 
}