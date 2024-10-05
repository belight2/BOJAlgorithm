#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define X first
#define Y second

using namespace std;

int n, c, x;
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
	return a.X > b.X;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> c;
	vector<pair<int,int>> v;
	for(int i = 0; i < n; i++){
		cin >> x;
		bool chk = false;
		for(auto &cur : v ){
			if(cur.Y == x ){
				chk = true;
				cur.X++;
				break;
			}
		}
		if(!chk) v.push_back({1,x});
	}
	stable_sort(v.begin(), v.end(), cmp);
	for(auto cur : v){
		while(cur.X--) cout << cur.Y << ' ';
	}
}
