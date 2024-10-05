#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <tuple>
#include <utility>
#define X first
#define Y second

using namespace std;

const int INF = 1e9 + 10;
int v, e;
int start_point;
vector<pair<int,int>> adj[20005];
int d[20005];
priority_queue< pair<int,int>,
				vector<pair<int,int>>,
				greater<pair<int,int>>> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e >> start_point;
	fill(d, d+v+1, INF);
	while(e--){
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({cost, b});
	}
	d[start_point] = 0;
	pq.push({d[start_point], start_point});
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(d[cur.Y] != cur.X) continue;
		for(auto nxt : adj[cur.Y]){
			if(d[nxt.Y] <= d[cur.Y] + nxt.X ) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({d[nxt.Y], nxt.Y});
		}
	}
	for(int i = 1; i <= v; i++){
		if(d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}
}
