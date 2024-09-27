#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
int L, R, C;
int map[32][32][32];
int dist[32][32][32];
int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 1, 0, -1, 0, 0, 0 };
int dz[6] = { 0, 1, 0, -1, 0, 0 };
queue<tuple<int,int,int>> Q;
tuple<int,int,int> res;
int resX, resY, resZ;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		cin >> L >> R >> C;
		if(L == 0 && R == 0 && C == 0) break;
		for(int i = 0; i < L; i++)
			for(int j = 0; j < R; j++)
				fill(dist[i][j], dist[i][j]+C, 0);
		for(int i = 0; i < L; i++ ){
			for(int j = 0; j < R; j++){
				for(int k = 0; k < C; k++ ){
					char c;
					cin >> c;
					if( c == 'S'){
						Q.push(make_tuple(i,j,k));
						dist[i][j][k]++;
					}
					else if( c == 'E'){
						res = make_tuple(i,j,k);
					}
					map[i][j][k] = c;
				}
			}
		}
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();
			int curX, curY, curZ ;
			tie(curX, curY, curZ) = cur;
			for(int dir = 0; dir < 6; dir++){
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];
				if( nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C ) continue;
				if( map[nx][ny][nz] == '#' || dist[nx][ny][nz] > 0 ) continue;
				dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
				Q.push(make_tuple(nx,ny,nz));
			}
		}
		tie(resX,resY,resZ) = res;
		if(dist[resX][resY][resZ] == 0 ) cout << "Trapped!" << '\n';
		else cout << "Escaped in "<< dist[resX][resY][resZ]-1 << " minute(s)."<< '\n';
	}
}