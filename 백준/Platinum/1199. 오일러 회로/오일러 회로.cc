#include <iostream>
using namespace std;

int v;
int adj_matrix[1005][1005];
int chk[1005];
int degree[1005];
void EulerianCircuit(int cur){
	for(; chk[cur] <= v; chk[cur]++){
		int nxt = chk[cur];
		while(adj_matrix[cur][nxt]){
			adj_matrix[cur][nxt]--;
			adj_matrix[nxt][cur]--;
			EulerianCircuit(nxt);
		}
	}
	cout << cur << ' ';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v;
	for(int i = 1; i <= v; i++){
		for(int j = 1; j <= v; j++){
			cin >> adj_matrix[i][j];
			degree[i] += adj_matrix[i][j];
			degree[j] += adj_matrix[i][j];
		}
	}
	fill(chk, chk+v+1, 1);
	// 차수가 홀수인 정점이 있으면
	// 오일러 회로가 성립하지않음
	for(int i = 1; i <= v; i++){
		degree[i] /= 2; // 양방향 그래프이므로 2로 나눔
		if(degree[i]&1){
			cout << "-1\n";
			return 0;
		}
	}
	EulerianCircuit(1);
}
