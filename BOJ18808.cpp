#include <iostream>

using namespace std;
int n, m, k;
int monitor[42][42];
int r, c;
int sticker[11][11];
int res = 0;

// ��ƼĿ ����� �Է¹޴� �Լ�
void print_sticker(){
	for(int i = 0; i < r; i++ )
		for(int j = 0; j < c; j++ )
			cin >> sticker[i][j];
}

// ������ ���� ���� �� �ִ� ��ġ�� �Ǵ����ִ� �Լ� 
bool isPos(int row, int col, int ang){
	// 0��
	if( ang == 0 ){
		// ��ƼĿ�� ����� ������ ���������� �ȵ� 
		if( row + r > n || col + c > m ) return false;
		// ���� ��ġ���� ��ƼĿ�� ���� �� �ִ��� Ȯ��
		for(int i = 0; i < r; i++ ) for(int j = 0; j < c; j++ )
		if( monitor[row+i][col+j] == 1 and sticker[i][j] == 1 ) return false;
	} 
	// 90��
	else if( ang == 1 ){
		if( row + c > n || col + r > m ) return false;
		for(int i = 0; i < c; i++ ) for(int j = r - 1; j >= 0; j-- )
		if( monitor[row+i][col+r-1-j] == 1 and sticker[j][i] == 1 ) return false;
	} 
	// 180�� 
	else if( ang == 2 ){
		if( row + r > n || col + c > m ) return false;
		for(int i = r - 1; i >= 0; i-- ) for(int j = c - 1; j >= 0; j-- )
		if( monitor[row+r-1-i][col+c-1-j] == 1 and sticker[i][j] == 1 ) return false;
	}
	// 270��
	else{
		if( row + c > n || col + r > m ) return false;
		for(int i = c - 1; i >= 0; i--) for(int j = 0; j < r; j++ )
		if( monitor[row+c-1-i][col+j] == 1 and sticker[j][i] == 1 ) return false;
	}
	// Ž�� ��� ���� �� ����
	return true; 
}
// ������ ���߾�  ����Ϳ� ��ƼĿ�� �ٿ��ִ� �Լ� 
void Put_Sticker(int row, int col, int angle){
	// 0�� 
	if( angle == 0 ){
		for( int i = 0; i < r; i++ ) 
			for(int j = 0; j < c; j++ ){
				int x = row+i; int y = col+j;
				//��ƼĿ �κп� ���� 0�̸� �Ѿ��. 
				if(sticker[i][j] == 0) continue;
				monitor[x][y] = sticker[i][j]; 
			}
			
	}
	// 90�� 
	else if( angle == 1 ){
		for(int i = 0; i < c; i++)
			for(int j = r-1; j >= 0; j--){
				int x = row + i; int y = col+r-1-j;
				if(sticker[j][i] == 0 ) continue;
				monitor[x][y] = sticker[j][i];
			}
		
	}
	// 180�� 
	else if( angle == 2 ){
		for(int i = r-1; i >= 0; i--)
			for(int j = c-1; j >= 0; j--){
				int x = row+r-1-i; int y = col+c-1-j;
				if(sticker[i][j] == 0 ) continue;
				monitor[x][y] = sticker[i][j];
			}
	}
	// 270�� 
	else{
		for(int i = c - 1; i >= 0; i--)
			for(int j = 0; j < r; j++){
				int x = row+c-1-i; int y = col+j;
				if(sticker[j][i] == 0 ) continue;
				monitor[x][y] = sticker[j][i];
			}
	}
}
// ���� �� �ִ� ��ġ�� ��ƼĿ�� ���̴� �Լ� 
void search_N_put(){
	// �� �������� ���� �� �ִ� ��ġ�� ã�´�.
	// ���� �� ���ٸ� ȸ���Ѵ�. 
	for(int angle = 0; angle < 4; angle++ )
		for(int row_idx = 0; row_idx < n; row_idx++)
			for(int col_idx = 0; col_idx < m; col_idx++ )
				//���� �� �ִٸ� ��ƼĿ�� ���� �� �Լ��� �����Ѵ�. 
				if( isPos(row_idx, col_idx, angle) ){
					Put_Sticker(row_idx, col_idx, angle );
					return;
				}
}



// ����Ϳ� ���� ��ƼĿ�� ũ�⸦ �����ִ� �Լ� 
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
