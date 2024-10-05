#include <iostream>
#include <queue>

using namespace std;

int map[100001];
int dx[3] = { -1,  1,  2 };
queue<int> Q;
int k;
void BFS(){
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		
		if( cur == k ){
				cout << map[cur] - 1;
				return;
			}
			
		for(int dir = 0; dir < 3; dir++){
			int idx = cur + dx[dir];
			if( dir == 2 ) idx = cur * dx[dir];
			
			if( idx < 0 || idx >= 100001 ) continue;
			if( map[idx] > 0 ) continue;
			
			map[idx] = map[cur] + 1;
			Q.push(idx);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n >> k;
	map[n]++;
	Q.push(n);
	BFS();
}