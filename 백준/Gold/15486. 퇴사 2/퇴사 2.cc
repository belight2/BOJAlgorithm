#include <iostream>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;

int n;
pair<int,int> TP[1500005];
int DP[1500005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	// TP[i].X = Ti, TP[i].Y = Pi 이다. 
	for(int i = 1; i <= n; i++) cin >> TP[i].X >> TP[i].Y; 
	
	// 다이나믹 프로그래밍
	for(int i = n; i >= 1; i--){
		if(i + TP[i].X <= n + 1){
			DP[i] = max(DP[i+TP[i].X] + TP[i].Y, DP[i+1]);
		}
		else DP[i] = DP[i+1];
	}
	cout << *max_element(DP, DP+n+1);
}
