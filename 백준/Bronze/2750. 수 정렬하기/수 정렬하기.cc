#include <iostream>
using namespace std;
int a[1005];
int tmp[1005];
int n;

void merge(int st, int en){
	int mid = (st+en)/2;
	int lidx = st;
	int ridx = mid;
	for(int i = st; i < en; i++){
		if( lidx >= mid ) tmp[i] = a[ridx++];
		else if( ridx >= en ) tmp[i] = a[lidx++];
		else if( a[lidx] > a[ridx] ) tmp[i] = a[ridx++];
		else tmp[i] = a[lidx++];
	}
	for(int i = st; i < en; i++ ) a[i] = tmp[i];
}
void merge_sort(int st, int en){
	if( en == st + 1 ) return;
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
	for(int i = 0; i < n; i++ ) cin >> a[i];
	merge_sort(0, n);
	for(int i = 0; i < n; i++) cout << a[i] << '\n';
}
