#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath> 
#define X first
#define Y second
using namespace std;

int n, m;
int lab[9][9];
int lab2[9][9];
int safe_area;
int res = 0; // 결과값 
vector<pair<int,int>> virus; //바이러스의 위치를 저장
 
// 빈 칸의 위치를 저장, brute.size() -> 빈 칸의 개수
vector<pair<int,int>> brute;
pair<int,int> choose[3];
bool isused[65];

queue<pair<int,int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void solve(){
	safe_area = brute.size() - 3;
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < m; j++){
			lab2[i][j] = lab[i][j];
		}
	}
	for(int i = 0; i < 3; i++ ) lab2[choose[i].X][choose[i].Y]++;
	for(int i = 0; i < virus.size(); i++ ) Q.push({virus[i]});
	while(!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
			if(lab2[nx][ny] == 0 ){
				lab2[nx][ny] = 2;
				Q.push({nx,ny});
				safe_area--;
			}
		}
	}
	res = max( res, safe_area );
}
void decide_wall(int k, int idx){
	if( k == 3 ){
		solve();
		return;
	}
	for(int i = idx; i < brute.size(); i++ ){
		if(!isused[i]){
			isused[i] = true;
			choose[k] = brute[i];
			decide_wall(k+1, i);
			isused[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> lab[i][j];
			if( lab[i][j] == 0 ) brute.push_back({i,j});
			else if(lab[i][j] == 2 ) virus.push_back({i,j});
		}
	}
	decide_wall(0,0);
	cout << res;
}
