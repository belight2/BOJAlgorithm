#include <iostream>
#include <vector>
using namespace std;
int n, e, x, cnt, nl[1000001];
vector<int> v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> e;
		nl[e]++;
		v.push_back(e);
	}
	cin >> x;
	for(int i : v){
		if(x-i <= 1000000 && x-i >0){
			if( i != x - i && nl[x-i] == 1){
				nl[x-i]--;
				nl[i]--;
				cnt++;
			}
			
		}
	}
	cout << cnt;
}