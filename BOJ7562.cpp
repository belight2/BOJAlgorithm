#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second

using namespace std;

int dist[303][303];
int n;
int x, y, r, z;

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

void BFS(queue<pair<int,int>> Q){
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 8; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
			if( nx == r && ny == z ){
				cout << dist[cur.X][cur.Y] << '\n';
				return;
			}
			if( dist[nx][ny] > 0 ) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx,ny});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		queue<pair<int,int>> Q;
		cin >> n;
		for(int i = 0; i < n; i++ ) fill( dist[i], dist[i]+n, 0 );
		cin >> x >> y;
		Q.push({x,y});
		dist[x][y] = 1;
		cin >> r >> z;
		if(x == r && y == z ) cout << 0 ;
		else BFS(Q);
	}
}
