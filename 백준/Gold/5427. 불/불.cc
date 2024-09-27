#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second

using namespace std;

char map[1001][1001];
int Fdist[1001][1001];
int Sdist[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int w, h, t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--){
		bool escape = false;
		queue<pair<int,int>> FQ;
		queue<pair<int,int>> Q;
		cin >> w >> h;
		for(int i = 0; i < h; i++){
			fill(Fdist[i], Fdist[i]+w, 0);
			fill(Sdist[i], Sdist[i]+w, 0);
		}
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				char c;
				cin >> c;
				if( c == '#') map[i][j] = c;
				else{
					if( c == '@' ) {
						Q.push({i,j});
						Sdist[i][j] = 1;
					}
					if( c == '*' ){
						FQ.push({i,j});
						Fdist[i][j] = 1;
					}
					map[i][j] = c;
				}		
			}
		}
		while(!FQ.empty()){
			pair<int,int> cur = FQ.front(); FQ.pop();
			for(int dir = 0; dir < 4; dir++ ){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if( nx < 0 || nx >= h || ny < 0 || ny >= w ) continue;
				if( map[nx][ny] == '#' ) continue;
				if(Fdist[nx][ny]) continue;
				
				Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
				FQ.push({nx,ny});
			}
		}
		
		while(!Q.empty() && (!escape)){
			pair<int,int> cur = Q.front(); Q.pop();
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if( nx < 0 || nx >= h || ny < 0 || ny >= w ){
						cout << Sdist[cur.X][cur.Y] << '\n';
						escape = true;
						break;
				}
				
				if(map[nx][ny] == '#') continue;
				if(Sdist[nx][ny]) continue;
				if(Fdist[nx][ny] != 0 && Fdist[nx][ny] <= Sdist[cur.X][cur.Y] + 1) continue;
				Sdist[nx][ny] = Sdist[cur.X][cur.Y] + 1;
				Q.push({nx,ny});
			}
		}
		
		if(!escape) cout << "IMPOSSIBLE" << '\n';
	}
}