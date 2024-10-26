// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005]; // 인접 리스트 
int deg[1005]; // 정점의 indegree 값 
int semester[1005]; // 각 과목을 이수할 수 있는 학기 정보

void topological_sort(){
  queue<int> q;
  
  for(int i = 1; i <= n; i++){
    if(deg[i]) continue;
    semester[i] = 1;
    q.push(i);
  }

  // 위상 정렬을 진행하면서 이수할 수 있는 학기 정보를 갱신합니다.
  while(q.size()){
    auto cur = q.front(); q.pop();
    for(int nxt : adj[cur]){
      deg[nxt]--;
      if(deg[nxt] > 0) continue;
      semester[nxt] = semester[cur] + 1;
      q.push(nxt);
    }
  }
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // 간선 삽입
    deg[v]++; // 정점 v의 indegree 값 증가 
  }

  // solve  
  topological_sort();

  // output
  for(int i = 1; i <= n; i++) cout << semester[i] << ' ';
}