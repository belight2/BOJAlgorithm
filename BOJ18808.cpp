#include <iostream>

using namespace std;
int n, m, k;
int monitor[42][42];
int r, c;
int sticker[11][11];
int res = 0;

// 스티커 모양을 입력받는 함수
void print_sticker(){
	for(int i = 0; i < r; i++ )
		for(int j = 0; j < c; j++ )
			cin >> sticker[i][j];
}

// 각도에 따라 붙일 수 있는 위치를 판단해주는 함수 
bool isPos(int row, int col, int ang){
	// 0도
	if( ang == 0 ){
		// 스티커가 모니터 밖으로 삐져나오면 안됨 
		if( row + r > n || col + c > m ) return false;
		// 현재 위치에서 스티커를 붙일 수 있는지 확인
		for(int i = 0; i < r; i++ ) for(int j = 0; j < c; j++ )
		if( monitor[row+i][col+j] == 1 and sticker[i][j] == 1 ) return false;
	} 
	// 90도
	else if( ang == 1 ){
		if( row + c > n || col + r > m ) return false;
		for(int i = 0; i < c; i++ ) for(int j = r - 1; j >= 0; j-- )
		if( monitor[row+i][col+r-1-j] == 1 and sticker[j][i] == 1 ) return false;
	} 
	// 180도 
	else if( ang == 2 ){
		if( row + r > n || col + c > m ) return false;
		for(int i = r - 1; i >= 0; i-- ) for(int j = c - 1; j >= 0; j-- )
		if( monitor[row+r-1-i][col+c-1-j] == 1 and sticker[i][j] == 1 ) return false;
	}
	// 270도
	else{
		if( row + c > n || col + r > m ) return false;
		for(int i = c - 1; i >= 0; i--) for(int j = 0; j < r; j++ )
		if( monitor[row+c-1-i][col+j] == 1 and sticker[j][i] == 1 ) return false;
	}
	// 탐색 결과 붙일 수 있음
	return true; 
}
// 각도에 맞추어  모니터에 스티커를 붙여주는 함수 
void Put_Sticker(int row, int col, int angle){
	// 0도 
	if( angle == 0 ){
		for( int i = 0; i < r; i++ ) 
			for(int j = 0; j < c; j++ ){
				int x = row+i; int y = col+j;
				//스티커 부분에 값이 0이면 넘어간다. 
				if(sticker[i][j] == 0) continue;
				monitor[x][y] = sticker[i][j]; 
			}
			
	}
	// 90도 
	else if( angle == 1 ){
		for(int i = 0; i < c; i++)
			for(int j = r-1; j >= 0; j--){
				int x = row + i; int y = col+r-1-j;
				if(sticker[j][i] == 0 ) continue;
				monitor[x][y] = sticker[j][i];
			}
		
	}
	// 180도 
	else if( angle == 2 ){
		for(int i = r-1; i >= 0; i--)
			for(int j = c-1; j >= 0; j--){
				int x = row+r-1-i; int y = col+c-1-j;
				if(sticker[i][j] == 0 ) continue;
				monitor[x][y] = sticker[i][j];
			}
	}
	// 270도 
	else{
		for(int i = c - 1; i >= 0; i--)
			for(int j = 0; j < r; j++){
				int x = row+c-1-i; int y = col+j;
				if(sticker[j][i] == 0 ) continue;
				monitor[x][y] = sticker[j][i];
			}
	}
}
// 붙일 수 있는 위치에 스티커를 붙이는 함수 
void search_N_put(){
	// 현 각도에서 붙일 수 있는 위치를 찾는다.
	// 붙일 수 없다면 회전한다. 
	for(int angle = 0; angle < 4; angle++ )
		for(int row_idx = 0; row_idx < n; row_idx++)
			for(int col_idx = 0; col_idx < m; col_idx++ )
				//붙일 수 있다면 스티커를 붙인 후 함수를 종료한다. 
				if( isPos(row_idx, col_idx, angle) ){
					Put_Sticker(row_idx, col_idx, angle );
					return;
				}
}



// 모니터에 붙인 스티커의 크기를 구해주는 함수 
void checking_Monitor(){
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	if(monitor[i][j] == 1 ) res++;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	while(k--){
		cin >> r >> c;
		print_sticker();
		search_N_put();
	}
	checking_Monitor();
	cout << res;
}
