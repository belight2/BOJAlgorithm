#include <iostream>
#include <vector>
using namespace std;
int a, b;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	vector<bool> p(b+1, 1);
	p[1] = 0;
	for(int i = 2; i * i <= b; i++){
		if(!p[i]) continue;
		for(int j = i * i; j <= b; j+=i ) p[j] = 0;
	}
	for(int i = a; i <= b; i++){
		if(p[i]) cout << i << '\n';
	}
}
