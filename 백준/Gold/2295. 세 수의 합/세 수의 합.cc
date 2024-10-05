#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int n;
ll a[1005];
vector<ll> m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			m.push_back(a[i] + a[j]);
	sort(m.begin(), m.end());
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(binary_search(m.begin(), m.end(), a[i] - a[j])){
				cout << a[i];
				return 0;
			}
		}
	}
}
