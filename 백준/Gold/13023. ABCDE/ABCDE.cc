#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const char nl = '\n';
int n, m, u, v;
vector<int> adj[2001];
vector<bool> vis(2001);

void solve(int idx, int k){
	if(k == 4){
		cout << 1 << nl;
		exit(0);	
	}
	for(auto nxt : adj[idx]){
		if(!vis[nxt]){
			vis[nxt] = 1;
			solve(nxt, k+1);
			vis[nxt] = 0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < n; i++){
		vis[i] = 1;
		solve(i, 0);
		vis[i] = 0;
	}
	cout << 0 << nl;
}