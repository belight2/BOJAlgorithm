#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
 
using namespace std;
int v, e;
tuple<int,int,int> edge[100005];
vector<int> p(100005, -1);
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
	cin >> v >> e;
	for(int i = 0; i < e; i++){
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = make_tuple(cost, a, b);
	}
	sort(edge, edge+e);
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i < e; i++){
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if(!is_diff_tree(a,b)) continue;
		ans += cost;
		cnt++;
		if(cnt == v-1) break;
	}
	cout << ans;
}
