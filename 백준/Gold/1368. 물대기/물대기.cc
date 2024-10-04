#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;
int v;
vector<int> p(305, -1);
tuple<int,int,int> edge[100005];
int find(int x){
	if(p[x] < 0) return x;
	return p[x] = find(p[x]);
}
bool is_diff_tree(int u, int v){
	u = find(u); v = find(v);
	if(u == v) return 0;
	
	if(p[u] == p[v]) p[u]--;
	if(p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v;
	int e = 0; //간선 개수 
	for(int i = 1; i <= v; i++){
		int cost;
		cin >> cost;
		edge[e++] = make_tuple(cost, i, v+1);
	}
	for(int i = 1; i <= v; i++){
		for(int j = 1; j <= v; j++){
			int cost;
			cin >> cost;
			if(i >= j) continue;
			edge[e++] = make_tuple(cost, i, j);
		}
	}
	v++;
	sort(edge, edge+e);
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i <= e; i++){
		int cost, a, b;
		tie(cost,a,b) = edge[i];
		if(!is_diff_tree(a,b)) continue;
		ans += cost;
		cnt ++;
		if(cnt == v-1) break;
	}
	cout << ans;
}
