#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

int n, m, h;
int cnt;
vector<pair<int,int>> v;
int map[35][15];
int dx[3] = { 1, 1, 1 }; // 아래, 오른쪽, 왼쪽 
int dy[3] = { 0, 1, -1 };
queue<pair<int,int>> Q;
bool success = false;

int move(int x, int y){
	Q.push({x,y});
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		int dir = map[cur.X][cur.Y];
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];
		if( nx == h+1 ) return ny;
		Q.push({nx,ny});
	}
}
void solve(){
	for(int i = 1; i <= n; i++){
		int res = move(1,i);
		if(res != i ) return;
	}
	success = true;
}
void decide(int k,int idx){
	if( k == cnt ){
		solve();
		return;
	}
	for(int i = idx; i < v.size(); i++){
		int curX = v[i].X;
		int curY = v[i].Y;
		if(map[curX][curY] == 0 && map[curX][curY+1] == 0 ){
			map[curX][curY] = 1; map[curX][curY+1] = 2;
			decide(k+1, i);
			if(success) return;
			map[curX][curY] = 0; map[curX][curY+1] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		map[x][y] = 1; map[x][y+1] = 2; 
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= n-1; j++){
			v.push_back({i,j});
		}
	}
	for(int i = 0; i < 4; i++){
		decide(0, 0);
		if(success){
			cout << i;
			return 0;
		}
		cnt++;
	}
	cout << -1;
}

