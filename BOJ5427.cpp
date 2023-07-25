#include <iostream>
#include <queue>
#include <utility>
#include <string>
#define X first
#define Y second

using namespace std;

queue<pair<int,int>> FQ;
queue<pair<int,int>> Q;
char map[1001][1001];
int Fdist[1001][1001];
int Sdist[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int w, h;
void FBFS(){
	while(!FQ.empty()){
		pair<int,int> cur = FQ.front(); FQ.pop();
		for(int dir = 0; dir < 4; dir++ ){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= h || ny < 0 || ny > w ) continue;
			if( map[nx][ny] == '#' || Fdist[nx][ny] > 0) continue;
			Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
			FQ.push({nx,ny});
		}
	}
}
void BFS(){
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= h || ny < 0 || ny >= w ){
				cout << Sdist[cur.X][cur.Y] << '\n';
				return;
			}
			if(Sdist[nx][ny]) continue;
			if(map[nx][ny] == '#' || Fdist[nx][ny] <= Sdist[cur.X][cur.Y] + 1) continue;
			Sdist[nx][ny] = Sdist[cur.X][cur.Y] + 1;
			Q.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		Q = queue<pair<int,int>>();
		cin >> w >> h;
		for(int i = 0; i < h; i++){
			fill(Fdist[i], Fdist[i]+w, 0);
			fill(Sdist[i], Sdist[i]+w, 0);
		}
		string s;
		for(int i = 0; i < h; i++){
			cin >> s;
			for(int j = 0; j < w; j++){
				if( s[j] == '*' ){
					if(Fdist[i][j] == 0){
						FQ.push({i,j});
						Fdist[i][j]++;
					}
				}
				if( s[j] == '@' ) {
					Q.push({i,j});
					Sdist[i][j]++;
				}
				map[i][j] = s[j];
			}
		}
		FBFS();
		BFS();
	}
}
