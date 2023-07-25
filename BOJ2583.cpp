#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int map[103][103];
int vis[103][103];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int,int>> Q;
vector<int> area;
int m, n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> k;
	int area_number = 0;
	int area_chk = 0;
	for(int t = 0; t < k; t++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		for(int i = a; i < c; i++){
			for(int j = b; j < d; j++){
				if(map[i][j] == 1) continue;
				map[i][j]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 0 && vis[i][j] == 0 ){
				Q.push({i,j});
				vis[i][j]++;
				area_number++;
				area_chk++;
				while(!Q.empty()){
					pair<int,int> cur = Q.front(); Q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if( nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
						if( vis[nx][ny] || map[nx][ny] == 1) continue;
						vis[nx][ny]++;
						Q.push({nx, ny});
						area_chk++;
					}
				}
				area.push_back(area_chk);
				area_chk = 0;
			}
		}
	}
	sort(area.begin(), area.end());
	cout << area_number << '\n';
	for(int x : area ) cout << x << ' ';
}
