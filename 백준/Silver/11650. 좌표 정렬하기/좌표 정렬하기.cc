#include <iostream>
#include <algorithm>
#include <utility>
#define X first
#define Y second

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	if( a.X == b.X )
		return a.Y < b.Y;
	return a.X < b.X;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	pair<int,int> arr[n];
	for(auto& data : arr){
		cin >> data.X >> data.Y;
	}
	sort(arr, arr+n, cmp);
	for(auto cur : arr){
		cout << cur.X <<' '<<cur.Y <<'\n';
	}
}
