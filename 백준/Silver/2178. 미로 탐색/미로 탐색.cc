#include <iostream>
#include <queue>
#include <utility>
#include <string>
#define X first
#define Y second
using namespace std;

queue<pair<int, int>> Q;
char board[101][101];
int dist[101][101];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(){
	while(!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if( dist[nx][ny] > 0 || board[nx][ny] != '1' ) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
}

int main(){
	string s;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++){
			board[i][j] = s[j];
		}
	}
	dist[0][0] = 1;
	Q.push({0, 0});
	BFS();
	cout << dist[n-1][m-1];
}