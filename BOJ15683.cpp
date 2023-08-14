#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define X first
#define Y second

using namespace std;

//ī�޶��� ��ġ�� ������ ������ ���� 
//( ��, ��)�� ���� 
vector<pair<int,int>> cctv;
int Dir[10]; // ������ ������ ������ �迭
bool isused[10]; //������ ���⿡ ���ؼ� 
int map[10][10]; //CCTV ��ġ�� ���� ��ġ�� ����� �迭
int map2[10][10]; //CCTV ���� ������ ä�� �迭 
int N, M; // �迭�� ��, �� 
int res = 0;

void fill_top(int row, int col){
	for(int idx = row-1; idx >= 0; idx--){
		if(map2[idx][col] == 6 ) return;
		if(map2[idx][col] != 0 ) continue;
		map2[idx][col] = 7;
	}
}
void fill_right(int row, int col){
	for(int idx = col+1; idx < M; idx++){
		if(map2[row][idx] == 6 ) return;
		if(map2[row][idx] != 0 ) continue;
		map2[row][idx] = 7;
	}
}
void fill_under(int row, int col){
	for(int idx = row+1; idx < N; idx++){
		if(map2[idx][col] == 6 ) return;
		if(map2[idx][col] != 0 ) continue;
		map2[idx][col] = 7;
	}
}
void fill_left(int row, int col){
	for(int idx = col-1; idx >= 0; idx--){
		if(map2[row][idx] == 6 ) return;
		if(map2[row][idx] != 0 ) continue;
		map2[row][idx] = 7;
	}
}
//CCTV�� �����ϴ� ���� �迭�� ä���ִ� �Լ� 
void fill_area(){
	//�迭 ���� 
	for(int i = 0; i < N; i++ )
		for(int j = 0; j < M; j++ )
			map2[i][j] = map[i][j];
	for(int i = 0; i < cctv.size(); i++){
		int x, y;
		x = cctv[i].X;
		y = cctv[i].Y;
		int dir = Dir[i]; 
		if(map[x][y] == 1){
			if( dir == 0 ){
				fill_right(x,y);
			}
			else if( dir == 1 ){
				fill_under(x,y);
			}
			else if( dir == 2 ){
				fill_left(x,y);
			}
			else{
				fill_top(x,y);
			}
		}
		else if(map[x][y] == 2){
			if( dir%2 == 0 ){
				fill_left(x,y); fill_right(x,y);
			}
			else{
				fill_top(x,y); fill_under(x,y);
			}
		}
		else if(map[x][y] == 3){
			if( dir == 0 ){
				fill_top(x,y); fill_right(x,y);
			}
			else if( dir == 1 ){
				fill_right(x,y); fill_under(x,y);
			}
			else if( dir == 2 ){
				fill_under(x,y); fill_left(x,y);
			}
			else{
				fill_left(x,y); fill_top(x,y);
			}
		}
		else if(map[x][y] == 4){
			if( dir == 0 ){
				fill_left(x,y); fill_top(x,y); fill_right(x,y);
			}
			else if( dir == 1 ){
				fill_top(x,y); fill_right(x,y); fill_under(x,y);
			}
			else if( dir == 2 ){
				fill_right(x,y); fill_under(x,y); fill_left(x,y);
			}
			else{
				fill_under(x,y); fill_left(x,y); fill_top(x,y);
			}
		}
		else if(map[x][y] == 5){
			fill_top(x,y);	fill_right(x,y); fill_under(x,y); fill_left(x,y);
		}
	}
	int mn = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(map2[i][j] == 0 ) mn++;
		}
	}
	res = min(res,mn);
}
// 4^8 =�� 65,536������ 
void func(int k){
	if( k == cctv.size() ){
		fill_area();
		return;
	}
	for(int i = 0; i < 4; i++ ){
		if(!isused[k]){
			isused[k] = true;
			Dir[k] = i;
			func(k+1);
			isused[k] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	res = M*N;
	// ������ �Է¹ް�, cctv ��ġ�� ���� 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			if(map[i][j] != 0 && map[i][j] != 6){ 
				cctv.push_back({i,j});
			}
		}
	}
	func(0);
	cout << res;
}
