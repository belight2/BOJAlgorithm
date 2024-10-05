#include <iostream>
#include <deque>
#include <utility>
#define X first
#define Y second

using namespace std;

int N; //보드의 크기
int board[101][101]; // 보드
bool snake_body[101][101]; //보드판에서 뱀이 있는 위치를 저장 
int apple; //사과의 개수
int L, X; //뱀 방향 전환 횟수, 전환할 때 게임 시간
char C; //뱀이 전환할 방향
deque<pair<int, char>> rotat;//인덱스는 시간, 각 시간에 방향이 있음 
int time; //게임 시간
deque<pair<int,int>> snake;
int dir = 0; //뱀의 방향 
int dx[4] = { 0, 1, 0, -1 }; // 동, 남, 서, 북   
int dy[4] = { 1, 0, -1, 0 };
void move_snake(){
	while(true){
		int t = rotat.front().X; int r = rotat.front().Y;
		if( t == time && r == 'L'){
			dir = (dir + 3)%4;
			rotat.pop_front();
		}
		else if(t == time && r == 'D'){
			dir = (dir + 1)%4;
			rotat.pop_front();
		}
		int nx = snake.front().X + dx[dir];
		int ny = snake.front().Y + dy[dir];
		if( nx < 0 || nx >= N || ny < 0 || ny >= N ) return;
		if( snake_body[nx][ny] == true ) return;
		
		snake_body[nx][ny] = true;
		snake.push_front({nx,ny});
		
		//이동할 칸에 사과가 있음
		if( board[nx][ny] == 1 ) board[nx][ny] = 0;
		//이동할 칸에 사과가 없음 
		else{
			int prvX = snake.back().X;
			int prvY = snake.back().Y;
			snake_body[prvX][prvY] = false;
			snake.pop_back();
		}
		time++;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> apple;
	for(int i = 0; i < apple; i++){
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}
	
	snake.push_back({0,0});
	snake_body[0][0] = true;
	
	cin >> L;
	for(int i = 0 ; i < L; i++){
		cin >> X >> C;
		rotat.push_back({X,C});
	}
	move_snake();
	cout << time+1;
}