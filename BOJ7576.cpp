#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

queue<pair<int, int>> Q;
int tomato[1005][1005];
int days[1005][1005];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, x, cnt;

pair<int, int> BFS(){
	while(1){
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
			if( days[nx][ny] > 0 || tomato[nx][ny] != 0 ) continue;
			days[nx][ny] = days[cur.X][cur.Y] + 1;
			cnt--;
			Q.push({nx, ny});
		}
		if(Q.empty()) return cur;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> x;
			if( x == 0 ) cnt++;
			else if( x == 1 ){
				Q.push({i, j});
			}
			tomato[i][j] = x;
		}
	if( cnt == 0 ) cout << 0;
	else if(Q.empty()) cout << -1;
	else {
		pair<int, int> x = BFS();
		if( cnt != 0 ) cout << -1;
		else cout << days[x.X][x.Y];
	}	
}
