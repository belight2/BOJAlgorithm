#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#define X first
#define Y second

using namespace std;
int n;
pair<int,string> arr[100005];

bool cmp(pair<int,string> a, pair<int,string> b){
	return a.X < b.X;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int x;
	string s;
	for(int i = 0; i < n;i++){
		cin >> x >> s;
		arr[i] = {x, s};
	}
	stable_sort(arr,arr+n,cmp);
	for(int i = 0; i < n; i++){
		cout << arr[i].X << ' ' << arr[i].Y << '\n';
	}
}
