#include <iostream>
using namespace std;
int arr[1000005];
int n;
int tmp[1000005];

void merge(int st, int en){
	int mid = (st+en)/2;
	int lidx = st;
	int ridx = mid;
	for(int i = st; i < en; i++){
		if( lidx >= mid ) tmp[i] = arr[ridx++];
		else if( ridx >= en ) tmp[i] = arr[lidx++];
		else if( arr[ridx] > arr[lidx] ) tmp[i] = arr[ridx++];
		else tmp[i] = arr[lidx++];
	}
	for(int i = st; i < en; i++ ) arr[i] = tmp[i];
}
void merge_sort(int st, int en){
	if(en == st+1) return;
	int mid = (st+en)/2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	merge_sort(0, n);
	for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}
