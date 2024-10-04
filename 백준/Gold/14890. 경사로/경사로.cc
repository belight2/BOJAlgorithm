#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, L;
int map[102][102];

int road;
void solve(int arr[]){
	bool slide[102];
	fill(slide, slide+n, false);
	int cur = arr[0];
	for(int i = 1; i < n; i++){
		if( cur == arr[i] ) continue;
		// 높은 칸과 높은 칸의 차이가 1이 아닌 경우 
		if( abs( cur - arr[i] ) != 1 ) return;
		
		if( cur < arr[i] ){
			// L개가 연속되지 않거나, 높이가 같지 않거나 이미 경사로가 쌓여져 있는지 조사 
			for(int j = 1; j <= L; j++ ) if( i - j < 0 || cur != arr[i-j] || slide[i-j] ) return;
			// 경사로 놓기 
			for(int j = 1; j <= L; j++ ) slide[ i - j ] = true;
		}
		else if( cur > arr[i] ){
			for(int j = 0; j < L; j++ ) if( i + j >= n || arr[i] != arr[i+j] || slide[i+j] ) return;
			for(int j = 0; j < L; j++ ) slide[i+j] = true;
		}
		cur = arr[i];
	}
	road++;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> L;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	int arr[102], arr2[102];
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < n; j++){
			arr[j] = map[i][j];
			arr2[j] = map[j][i];
		}
		solve(arr); solve(arr2);;
	}
	cout << road;
}
