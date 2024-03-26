#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
int n, m, k;
int mnt[42][42];
int r, c;
int stk[11][11];
int res = 0;

bool isPos(int row, int col, int ang){
	if( ang == 0 ){
		if( row+r > n || col+c > m ) return false;
		for(int i = 0; i < r; i++ ){
			for(int j = 0; j < c; j++){
				if(mnt[row+i][col+j] == 1 and stk[i][j] == 1) return false;
			}
		}
		return true;
	}
	else if( ang == 1 ){
		if( row + c > n || col + r > m) return false;
		for(int i = 0; i < c; i++){
			for(int j = r - 1; j >= 0; j-- ){
				if(mnt[row+i][col+r-1-j] == 1 and stk[j][i] == 1 ) return false;
 			}
		}
		return true;
	}
	else if( ang == 2 ){
		if( row + r > n || col + c > m ) return false;
		for(int i = r - 1; i >= 0; i--){
			for(int j = c - 1; j >= 0; j-- ){
				if(mnt[row + r - 1 - i][col + c - 1 - j] == 1 and stk[i][j] == 1 ) return false;
			}
		}
		return true;
	}
	else{
		if( row + c > n || col + r > m ) return false;
		for(int i = c - 1; i >= 0; i-- ){
			for(int j = 0; j < r; j++ ){
				if( mnt[row + c - 1 - i][col+j] == 1 and stk[j][i] == 1 ) return false; 
			}
		}
		return true;
	}
}
void putin(){
	for(int angle = 0; angle < 4; angle++){
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m ; j++ ){
				if(isPos(i,j,angle)){
					if(angle == 0){
						for(int x = 0; x < r; x++ ){
							for(int y = 0; y < c; y++){
								if(mnt[i+x][j+y] == 1 && stk[x][y] == 0) continue;
								mnt[i+x][j+y] = stk[x][y];
							}
						}
					}
					else if( angle == 1 ){
						for(int x = 0; x < c; x++){
							for(int y = r - 1; y >= 0; y-- ){
								if(mnt[i + x][j + r - 1 - y] == 1 && stk[y][x] == 0) continue;
								mnt[i + x][j + r - 1 - y] = stk[y][x];
 							}
						}
					}
					else if( angle == 2 ){
						for(int x = r - 1; x >= 0; x--){
							for(int y = c - 1; y >= 0; y-- ){
								if(mnt[i + r - 1 - x][j + c - 1 - y] == 1 && stk[x][y] == 0) continue;
								mnt[i + r - 1 - x][j + c - 1 - y] = stk[x][y];
							}
						}
					}
					else{
						for(int x = c - 1; x >= 0; x-- ){
							for(int y = 0; y < r; y++ ){
								if(mnt[ i + c - 1 - x][j + y ] == 1 && stk[y][x] == 0) continue;
								mnt[ i + c - 1 - x][j + y ] = stk[y][x];
							}
						}
					}
					return;
				
				}
			}
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	while(k--){
		cin >> r >> c;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin >> stk[i][j];
			}
		}
		putin();
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) if(mnt[i][j] == 1 ) res++;
	cout << res;
}