#include <iostream>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
int n, m, b;
int board[505][505];
int time[257];
const int INF = 0x7fffffff;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> b;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	fill(time, time+257, INF);
	for(int h = 0; h <= 256; h++){
		int tmp = b;
		time[h] = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(board[i][j] == h) continue;
				if(board[i][j] > h){
					time[h] += 2 * (board[i][j] - h);
					b += board[i][j] - h; 
				}
				else{
					time[h] += h - board[i][j];
					b -= h - board[i][j];
				}
			}
		}
		if( b < 0 ) time[h] = INF;
		b = tmp;
	}
	int res = *min_element(time, time+257);
	for(int i = 256; i >= 0; i--){
		if(time[i] != res) continue;
		cout << res << ' '<< i; 
		break;
	}
}