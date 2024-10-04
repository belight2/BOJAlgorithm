#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define X first
#define Y second

using namespace std;

int n;
int board[23][23];
int board2[23][23];
int dir[6];
queue<int> Q;
queue<int> printQ;
int res = 0;

void Plus_number(int x){
	if(Q.empty()) Q.push(x);
	else{
		if(Q.front() == x ) printQ.push(x*2);
		else{
			printQ.push(Q.front());
			Q.push(x);
		}
		Q.pop();
	}
	
}
void move_top(){
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < n; j++){
			if(board2[j][i] != 0) Plus_number(board2[j][i]);
		}
		while(!Q.empty()){
			printQ.push(Q.front()); Q.pop();
		}
		int row = 0;
		while(!printQ.empty()){
			board2[row][i] = printQ.front();
			printQ.pop();
			row++;
		}
		for(int j = row; j < n; j++) board2[j][i] = 0;
	}	
}
void move_right(){
	for(int i = 0; i < n; i++ ){
		for(int j = n - 1; j >= 0; j-- ){
			if( board2[i][j] != 0 ) Plus_number(board2[i][j]);
		}
		while(!Q.empty()){
			printQ.push(Q.front()); Q.pop();
		}
		int col = n - 1;
		while(!printQ.empty()){
			board2[i][col] = printQ.front();
			printQ.pop();
			col--;
		}
		for(int j = col; j >= 0; j-- ) board2[i][j] = 0;
	}
}
void move_under(){
	for(int i = 0; i < n; i++ ){
		for(int j = n - 1; j >= 0; j-- ){
			if(board2[j][i] != 0) Plus_number(board2[j][i]);
		}
		while(!Q.empty()){
			printQ.push(Q.front()); Q.pop();
		}
		int row = n-1;
		while(!printQ.empty()){
			board2[row][i] = printQ.front();
			printQ.pop();
			row--;
		}
		for(int j = row; j >= 0; j--) board2[j][i] = 0;
	}
}
void move_left(){
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < n; j++ ){
			if( board2[i][j] != 0 ) Plus_number(board2[i][j]);
		}
		while(!Q.empty()){
			printQ.push(Q.front()); Q.pop();
		}
		int col = 0;
		while(!printQ.empty()){
			board2[i][col] = printQ.front();
			printQ.pop();
			col++;
		}
		for(int j = col; j < n; j++ ) board2[i][j] = 0;
	}
}
void find_max(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			res = max( res, board2[i][j]);
		}
	}
}
void move_board(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board2[i][j] = board[i][j];
		}
	}
	for(int i = 0; i < 5; i++){
		if( dir[i] == 0 ) move_top();
		else if( dir[i] == 1 ) move_right();
		else if( dir[i] == 2 ) move_under();
		else move_left();
	}
	find_max();
}
// 백트래킹으로 5개의 방향을 정해주는 함수 
void Decide_dir( int k = 0 ){
	if( k == 5 ){
		move_board();
		return;
	}
	for(int i = 0; i < 4; i++ ){
		dir[k] = i;
		Decide_dir(k+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++ )
			cin >> board[i][j];
	Decide_dir(0);
	cout << res;
}