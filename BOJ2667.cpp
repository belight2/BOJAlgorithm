#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;
char map[26][26];
int vis[26][26];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int,int>> Q;
vector<int> house;
int hse_num;
int hse_ar;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			map[i][j] = c;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] == '1' && vis[i][j] == 0 ){
				hse_num++;
				vis[i][j]++;
				Q.push({i,j});
				hse_ar++;
				while(!Q.empty()){
					pair<int,int> cur = Q.front(); Q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if( nx < 0 || nx >= n || ny < 0 || ny >= n ) continue;
						if(vis[nx][ny] || map[nx][ny] == '0' ) continue;
						hse_ar++;
						vis[nx][ny]++;
						Q.push({nx, ny});
					}
				}
				house.push_back(hse_ar);
				hse_ar = 0;
			}
		}
	}
	sort(house.begin(), house.end());
	cout << hse_num << '\n';
	for(int x : house ) cout << x << '\n';
}
