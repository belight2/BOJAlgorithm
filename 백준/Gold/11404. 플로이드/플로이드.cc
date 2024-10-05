#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i<= n; i++){
		fill(d[i], d[i]+n+1, INF);
	}
	while(m--){
		int u, v, cost;
		cin >> u >> v >> cost;
		d[u][v] = min(d[u][v], cost);
	}
	for(int i = 1; i <= n; i++){
		d[i][i] = 0;
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(d[i][j] == INF) cout << "0 ";
			else cout << d[i][j] << ' ';
		}
		cout <<'\n';
	}
}
