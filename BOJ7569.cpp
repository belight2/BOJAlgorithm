#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
int h, m, n;
int raw; 
int map[103][103][103];
int days[103][103][103];
int dx[6] = { 0, 0, 0, 0, 1, -1 }; //높이 
int dy[6] = { 1, 0, -1, 0, 0, 0}; //행 
int dz[6] = { 0, 1, 0, -1, 0, 0}; //열
queue<tuple<int ,int, int>> Q; 

tuple<int,int,int> BFS(){
	while(1){
		tuple<int,int,int> cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for(int dir = 0; dir < 6; dir++){
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if( nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			if( map[nx][ny][nz] != 0 || days[nx][ny][nz] > 0 ) continue;
			raw--;
			days[nx][ny][nz] = days[curX][curY][curZ] + 1;
			Q.push(make_tuple(nx,ny,nz));
		}
		if(Q.empty()) return cur;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> h;
	int x;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < m; k++){
				cin >> x;
				map[i][j][k] = x;
				if( x == 0 ) raw++;
				if( x == 1 ){
					days[i][j][k]++;
					Q.push(make_tuple(i,j,k));
				}
			}			
	if( raw == 0 ) cout << 0;
	else if(Q.empty()) cout << -1;
	else{
		int x, y, z;
		tie(x,y,z) = BFS();
		if(raw != 0) cout << -1;
		else cout << days[x][y][z]-1;
	}
}
