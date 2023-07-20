#include <iostream>
#include <utility>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[502][502];
int vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFSAndRTA(pair<int, int> p){
	queue<pair<int, int >> Q;
	int ar = 0;
	vis[p.X][p.Y] = 1;
	Q.push(p);
	while(!Q.empty()){
		pair<int, int> cur = Q.front(); Q.pop();
		ar++;
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
			if( vis[nx][ny] || board[nx][ny] != 1 ) continue;
			vis[nx][ny] = 1;
			Q.push({nx, ny});
		}
	}
	return ar;
}
int main(){
	int maxArea = 0;
	int cmpArea = 0;
	int cnt = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if( !vis[i][j]&&board[i][j] == 1){
				cnt++;
				cmpArea = BFSAndRTA({i, j});
				if(cmpArea > maxArea) maxArea = cmpArea;		
			}
		}
	cout << cnt << '\n' << maxArea;
} 
