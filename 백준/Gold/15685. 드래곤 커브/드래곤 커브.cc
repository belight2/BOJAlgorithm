#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#define X first
#define Y second

using namespace std;

bool coor[102][102];
int n;
int x,y,d,g;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
stack<pair<int,int>> dragon;

void dragon_Curve(int d, int gene){
	vector<int> dir; //방향을 저장할 벡터 
	dir.push_back(d); //초기위치 저장
	while(gene--){
		int sz = dir.size();
		//방향 벡터를 뒤에서부터 확인 
		for(int idx = sz-1; idx >= 0; idx--){
			int new_dir = (dir[idx]+1) % 4; // 끝점에서 새로 이어갈 방향
			pair<int,int> cur = dragon.top(); // 끝점 위치 반환
			dragon.push({cur.X + dx[new_dir], cur.Y + dy[new_dir] }); // 좌표 스택에 삽입 
			dir.push_back(new_dir); // 방향 추가 
		}
	}
	// 드래곤 내 좌표들 좌표에 표시하기 
	while(!dragon.empty()){
		pair<int,int> cur = dragon.top(); dragon.pop();
		coor[cur.X][cur.Y] = true;
	}
}
int check_Rectangle(){
	int cnt = 0; // 사각형의 개수
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++ ){
			if(coor[i][j] && coor[i][j+1] && coor[i+1][j] && coor[i+1][j+1] )
				cnt++;
		}
	}
	return cnt; 
	
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while(n--){
		cin >> y >> x >> d >> g;
		dragon.push({x,y});
		dragon.push({x+dx[d], y+dy[d]});
		dragon_Curve(d,g);
	}
	int res = check_Rectangle(); // 1x1 정사각형 개수 세기 
	cout << res; 
}
