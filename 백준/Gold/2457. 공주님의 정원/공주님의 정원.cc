#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define X first
#define Y second

using namespace std;
int n;
vector<pair<int,int>> flower;
int ans;
pair<int,int> lastSelected = { 301, 301 };
pair<int,int> candidate = { 301, 301 };
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int a, b, c, d;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c >> d;
		flower.push_back({a*100+b, c*100+d});
	}
	sort(flower.begin(), flower.end());
	for(auto cur : flower){
		if(lastSelected.Y < cur.X){
			if(candidate.Y >= cur.X ){
				lastSelected = candidate;
				candidate = cur;
				ans++;
			}
			else{
				cout << 0; return 0;
			}
			
		}
		else if(lastSelected.Y >= cur.X && candidate.Y < cur.Y ){
			candidate = cur;	
		}
		if(candidate.Y > 1130){
			lastSelected = candidate;
			ans++;
			break;
		}
	}
	if(lastSelected.Y > 1130 ) cout << ans;
	else cout << 0;

}
