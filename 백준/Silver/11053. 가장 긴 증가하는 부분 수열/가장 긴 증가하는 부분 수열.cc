#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int DP[1001];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >>arr[i];
	fill(DP, DP+n, 1);
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
			if(arr[j] < arr[i] ) DP[i] = max(DP[i], DP[j]+1);
	cout << *max_element(DP,DP+n);		
}