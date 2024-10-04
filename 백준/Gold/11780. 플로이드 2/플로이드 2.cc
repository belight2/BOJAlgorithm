#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int dp[105][105];
int nxt[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) fill(dp[i], dp[i]+n+1, INF);
	
	while(m--){
		int u, v, cost;
		cin >> u >> v >> cost;
		dp[u][v] = min(dp[u][v], cost);
		nxt[u][v] = v;
	}
	for(int i = 1; i <= n; i++) dp[i][i] = 0;
	// dp
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <=n; j++){
				if(dp[i][k]+dp[k][j] < dp[i][j]){
					dp[i][j] = dp[i][k] + dp[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == INF) cout << "0 ";
			else cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	
	// 경로 출력
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == 0 || dp[i][j] == INF){
				cout << 0 << '\n';
				continue;
			}
			vector<int> path;
			int st = i;
			while(st != j){
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';
			for(int x : path) cout << x << ' ';
			cout << '\n';
		}
	} 
}
