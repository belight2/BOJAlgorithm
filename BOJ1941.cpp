#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#define X first
#define Y second

using namespace std;

const int N = 5;
char arr[6][6];
vector<pair<int,int>> v;
bool isUsed[6][6];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int,int>> Q;
int vis[6][6];
int res = 0;
void bfs(int x,int y){
	int n = 0;
	int sn = 0;
	for(int i = 0; i < N; i++ ) fill(vis[i], vis[i]+N, 0);
	Q.push({x,y}); n++;
	vis[x][y] = 1;
	if(arr[x][y] == 'S') sn++;
	while(!Q.empty()){
		pair<int,int> cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue;
			if( vis[nx][ny] != 0 || !isUsed[nx][ny] ) continue;
			vis[nx][ny] = 1;
			if(arr[nx][ny] == 'S') sn++;
			Q.push({nx,ny}); n++;
		}
	}
	if( n == 7 && sn >= 4 ) res++;
}
void func(int idx, int k){
	if( k == 7 ){
		bfs(v[idx].X, v[idx].Y);
		return;
	}
	for(int i = idx; i < N*N; i++ ){
		if(!isUsed[v[i].X][v[i].Y]){
			isUsed[v[i].X][v[i].Y] = true;
			func( i, k+1 );
			isUsed[v[i].X][v[i].Y] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < N; j++){
			arr[i][j] = s[j];
			v.push_back({i,j});
		}
	}
	func(0,0);
	cout << res;
}
