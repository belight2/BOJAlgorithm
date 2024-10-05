#include <iostream>
#include <cmath>
#include <utility>
#define X first
#define Y second

using namespace std;

int n, m;
int paper[502][502];
pair<int,int> tetro[19][4] = {
	//긴 막대기 
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } },
	//긴 막대기 회전 
	{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } },
	// 정사각형 
	{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } },
	// ㄴ자 
	{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 2, 1 } },
	// ㄴ자 ( 1 rotate ) 
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 } },
	// ㄴ자 ( 2 rotate ) 
	{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } },
	// ㄴ자 ( 3 rotate )
	{ { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
	// ㄴ자 대칭 
	{ { 0, 1 }, { 1, 1 }, { 2, 0 }, { 2, 1 } }, 
	//ㄴ자 대칭 ( 1 rotate )
	{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },
	// ㄴ자 대칭( 2 rotate ) 
	{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } },
	// ㄴ자 대칭( 3 rotate ) 
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } },
	// 번개 == 번개 ( 2 rotate ) 
	{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
	// 번개 ( 1 rotate ) == 번개 ( 3 rotate ) 
	{ { 1, 0 }, { 1, 1 }, { 0, 1 }, { 0, 2 } },
	// 번개 대칭 
	{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },
	// 번개 대칭 ( 1 rotate )
	{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },
	// ㅜ
	{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
	// ㅓ 
	{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },
	// ㅗ
	{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 } }, 
	// ㅏ
	{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } },  
};
int res = 0;

void solve(int x){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			bool isCal = true;
			int cal = 0;
			for(int k = 0; k < 4; k++){
				int nx = i + tetro[x][k].X;
				int ny = j + tetro[x][k].Y;
				if( nx < 0 || nx >= n || ny < 0 || ny >= m ){
					isCal = false;
					continue;
				}
				cal += paper[nx][ny];
			}
			if(isCal) res = max(res, cal);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> paper[i][j];
	for(int i = 0; i < 19; i++){
		solve(i);
	}
	cout << res;
}
