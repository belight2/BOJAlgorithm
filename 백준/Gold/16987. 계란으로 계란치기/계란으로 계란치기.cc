#include <iostream>
#include <cmath>
using namespace std;

int N;
int hp[9];
int dmg[9];
int mx = 0;
int broken = 0;

void func(int k){
	if( k == N ){
		mx = max(mx,broken);
		return;
	}
	if( hp[k] <= 0 || broken == N-1 ){
		func(k+1);
		return;
	}
	for(int i = 0; i < N; i++ ){
		if( i == k || hp[i] <= 0 ) continue;
		hp[k] -= dmg[i];
		hp[i] -= dmg[k];
		if(hp[k] <= 0 ) broken++;
		if(hp[i] <= 0 ) broken++;
		func(k+1);
		if(hp[k] <= 0) broken--;
		if(hp[i] <= 0 ) broken--;
		hp[k] += dmg[i];
		hp[i] += dmg[k];
		
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) cin >> hp[i] >> dmg[i];
	func(0);
	cout << mx;
}