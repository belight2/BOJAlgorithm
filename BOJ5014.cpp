#include <iostream>
#include <queue>

using namespace std;

int dist[1000002];
int F, S, G, U, D;
int dx[2];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> F >> S >> G >> U >> D;
	dx[0] = U; dx[1] = -1*D;
	Q.push(S);
	dist[S]++;
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		for(int dir = 0; dir < 2; dir++){
			int nx = cur + dx[dir];
			if( nx < 1 || nx > F ) continue;
			if(dist[nx] > 0) continue;
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
	}
	if(dist[G] == 0) cout << "use the stairs";
	else cout << dist[G] - 1;
}
