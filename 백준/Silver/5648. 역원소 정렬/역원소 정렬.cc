#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
long long p[15] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
100000000, 1000000000, 10000000000, 100000000000, 1000000000000 };

long long reverse(string num){
	long long res = 0;
	for(int i = num.length()-1; i >= 0; i--){
		int x = 1;
		char c = num[i];
		res += (c-'0')*p[i+1];
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	long long arr[n];
	string x;
	for(int i = 0; i < n; i++){
		cin >> x;
		arr[i] = reverse(x);
	}
	sort(arr, arr+n);
	for(long long x : arr){
		cout << x << '\n';
	}
	
}
