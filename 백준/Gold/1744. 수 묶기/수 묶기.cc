#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long ans;
int n;

void solve(const vector<int> &v){
	int size = v.size();
	for(int idx = 0; idx < size; idx++){
		int a = v[idx];
		if(idx+1 < size){
			int b = v[idx+1];
			if( a * b <= a + b ) ans += a;
			else{
				ans += ( a * b );
				idx++;
			}
		}
		else ans += a;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<int> neg;
	vector<int> pos;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if( x <= 0 ) neg.push_back(x);
		else pos.push_back(x);
	}
	sort(neg.begin(), neg.end());
	sort(pos.rbegin(), pos.rend());
	solve(neg);
	solve(pos);
	cout << ans;
}
