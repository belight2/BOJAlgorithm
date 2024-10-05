#include <iostream>
#include <algorithm>
using namespace std;
string a,b;
int len_a, len_b;
int D[1001][1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	len_a = a.size();
	len_b = b.size();
	// 초기값 설정
	// 좀 드러운데... 
	for(int i = 0; i < len_b; i++){
		if( a[0] == b[i] ){
			D[0][i] = 1;
		}
		else{
			if(i == 0) D[0][i] = 0;
			else D[0][i] = D[0][i - 1];
		}
	}
	//DP
	for(int i = 1; i < len_a; i++){
		for(int j = 0; j < len_b; j++){
			if(a[i] == b[j]){
				D[i][j] = D[i-1][j-1] + 1;
			}
			else{
				if(j == 0) D[i][j] = D[i-1][j];
				else D[i][j] = max(D[i-1][j], D[i][j-1]);
			}
		}
	}
	cout << *max_element(D[len_a-1], D[len_a-1] + len_b);
}
