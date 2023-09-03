#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#define X first
#define Y second

using namespace std;

bool coor[102][102];
int n;
int x,y,d,g;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
stack<pair<int,int>> dragon;

void dragon_Curve(int d, int gene){
	vector<int> dir; //������ ������ ���� 
	dir.push_back(d); //�ʱ���ġ ����
	while(gene--){
		int sz = dir.size();
		//���� ���͸� �ڿ������� Ȯ�� 
		for(int idx = sz-1; idx >= 0; idx--){
			int new_dir = (dir[idx]+1) % 4; // �������� ���� �̾ ����
			pair<int,int> cur = dragon.top(); // ���� ��ġ ��ȯ
			dragon.push({cur.X + dx[new_dir], cur.Y + dy[new_dir] }); // ��ǥ ���ÿ� ���� 
			dir.push_back(new_dir); // ���� �߰� 
		}
	}
	// �巡�� �� ��ǥ�� ��ǥ�� ǥ���ϱ� 
	while(!dragon.empty()){
		pair<int,int> cur = dragon.top(); dragon.pop();
		coor[cur.X][cur.Y] = true;
	}
}
int check_Rectangle(){
	int cnt = 0; // �簢���� ����
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++ ){
			if(coor[i][j] && coor[i][j+1] && coor[i+1][j] && coor[i+1][j+1] )
				cnt++;
		}
	}
	return cnt; 
	
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while(n--){
		cin >> y >> x >> d >> g;
		dragon.push({x,y});
		dragon.push({x+dx[d], y+dy[d]});
		dragon_Curve(d,g);
	}
	int res = check_Rectangle(); // 1x1 ���簢�� ���� ���� 
	cout << res; 
}

