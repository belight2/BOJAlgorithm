#include <iostream>
#include <utility>
#define X first
#define Y second

using namespace std;
int N, M;
int room[52][52];
int clean[52][52];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
pair<int, int> robot;
int front;
int res = 0;

bool isMess(){
	pair<int,int> cur = robot;
	for(int dir = 0; dir < 4; dir++){
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if(room[nx][ny] != 1 && clean[nx][ny] == 0 ) return true;
	}
	return false;
}
void operate(){
	while(true){
		//청소되지 않은 칸 청소 
		if( clean[robot.X][robot.Y] == 0 ){
			clean[robot.X][robot.Y]++;
			res++;
		}
		//주변 4칸 중 청소할 칸이 없다. 
		if(!isMess()){
			int back =  (front + 2) % 4;
			int nx = robot.X + dx[back]; int ny = robot.Y + dy[back];
			//뒤에가 벽이면 작동 중지
			if( room[nx][ny] == 1 ) return;
			//아니면 이동 
			else{
				robot = {nx,ny};
			} 
		}
		//청소할 칸이 있으면 
		else{
			front = (front+3)%4;
			int nx = robot.X + dx[front]; int ny = robot.Y + dy[front];
			if(room[nx][ny] == 0 && clean[nx][ny] == 0 ){
				robot = {nx,ny};	
			} 
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> robot.X >> robot.Y >> front;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> room[i][j];
		}
	}
	operate();
	cout << res;
}