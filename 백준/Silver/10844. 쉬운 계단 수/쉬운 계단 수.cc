#include <iostream>
#define mod %1000000000
using namespace std;
long long D[101][11];
int N;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//초기값 설정
	for(int n = 1; n <= 9; n++) D[1][n] = 1;
	cin >> N; // 계단의 길이 입력 
	for(int n = 2; n <= N; n++){
		for(int i = 1; i <= 8; i++){
			D[n][i] = ( D[n-1][i-1] + D[n-1][i+1] ) mod;
		}
		D[n][0] = D[n-1][1] mod;
		D[n][9] = D[n-1][8] mod;
	}
	long long ans = 0;
	for(int i = 0; i < 10; i++){
		ans += D[N][i];
	}
	cout << ans mod << '\n';
}