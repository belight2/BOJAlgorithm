#include <iostream>
#include <vector>
#define mod %1000000 
using namespace std;

long long dp[5001];
vector<int> v;
string s;
bool flag;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	v.push_back(0);
	for(char c : s) v.push_back(c-'0');
	dp[0] = 1;
	for(int i = 1; i < v.size(); i++){
		if(v[i] > 0) dp[i] = (dp[i] + dp[i-1]) mod;
		int x = v[i-1] * 10 + v[i];
		if(10 <= x && x <= 26) dp[i] = (dp[i] + dp[i-2]) mod;
	}
	cout << dp[v.size()-1] << '\n';
}
