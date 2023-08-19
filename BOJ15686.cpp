#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int map[52][52];
int n, m;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
int No_clo[15];
bool isused[15];
int res;

void calculateDistance(){
	int Sum = 0;
	for(int addr = 0; addr < house.size(); addr++){
		int chk_dist = 1000000000;
		for( int idx = 0; idx < m; idx++){
			int new_dist = abs(house[addr].X - chicken[No_clo[idx]].X) + abs(house[addr].Y - chicken[No_clo[idx]].Y);
			chk_dist = min( chk_dist, new_dist );
		}
		Sum += chk_dist;
	}
	res = min(res, Sum);
}

void choose(int k, int idx){
	if( k == m ){
		calculateDistance();
		return;
	}
	for(int i = idx; i < chicken.size(); i++){
		if(!isused[i]){
			isused[i] = true;
			No_clo[k] = i;
			choose(k+1, i);
			isused[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	res = 1000000000;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			if(map[i][j] == 1 ) house.push_back({ i, j });
			else if(map[i][j] == 2 ) chicken.push_back({ i , j });
		}
	} 
	// M 개의 치킨집을 고른뒤 도시의 치킨 거리를 구하는 백트래킹 함수 
	choose(0,0);
	cout << res; 
}
