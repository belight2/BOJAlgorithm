#include <iostream>
#include <queue>
#include <utility>
#include <string>
#define X first
#define Y second
using namespace std;

int r, c;
queue<pair<int,int>> Q;
queue<pair<int,int>> F;
char board[1001][1001];
int dist[1001][1001];
int Fdist[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void FBFS(){
	while(!F.empty()){
		pair<int, int> cur = F.front(); F.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= r || ny < 0 || ny >= c ) continue;
			if(board[nx][ny] == '#' || Fdist[nx][ny] > 0 ) continue;
			Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
			F.push({ nx, ny });
		}
	}
}
void BFS(){
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= r || ny < 0 || ny >= c ){
				cout << dist[cur.X][cur.Y]; return;
			}
			if( board[nx][ny] == '#' || dist[nx][ny] > 0 ) continue;
			if( Fdist[nx][ny] != 0 && dist[cur.X][cur.Y] + 1 >= Fdist[nx][ny] ) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}
	cout << "IMPOSSIBLE";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char data;
	string s;
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> s;
		for(int j = 0; j < c; j++){
			if( s[j] == 'J' ){
				dist[i][j]++;
				Q.push({i,j});
			}
			else if( s[j] == 'F'){
				Fdist[i][j]++;
				F.push({i,j});
			}
			board[i][j] = s[j];
		}
	}
	FBFS();
	BFS();
}
