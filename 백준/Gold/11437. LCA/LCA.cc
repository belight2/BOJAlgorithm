#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define log2(x) int(log10(x)/log10(2)) + 2
const char nl = '\n';
const int MXN = 1e5+5;
const int MXK = log2(MXN);
int n; // number of vertex
int m; // number of query
int P[MXK][MXN]; // p[i][j] : j의 2^i번째 윗 조상
int dep[MXN]; // dep[i] : i 정점의 depth
vi adj[MXN]; // 인접 리스트
vb chk(MXN); // 방문 배열

// u와 v의 최소 공통 조상을 찾아주는 함수
int lca(int u, int v){
  // 깊이가 더 큰 값이 u로 오도록 처리
  if(dep[u] < dep[v]) swap(u, v);
  // 두 정점의 깊이 차이
  int diff = dep[u] - dep[v];
  // u, v가 깊이가 같아지게 diff만큼 u를 위로 이동
  for(int i = MXK -1; i >= 0; i--){
    if(diff&(1<<i)) u = P[i][u];
  }
  // 이동 시킨 두 정점이 서로 같은 경우 그 값을 반환해준다.
  if(u == v) return u;

  // 위에 부모가 같을 때까지 이동시킨다.
  for(int i = MXK - 1; i >= 0; i--){
    if(P[i][u] > 0 && P[i][u] != P[i][v]){
      u = P[i][u];
      v = P[i][v];
    }
  }
  // u와 v의 깊이가 같아졌을 때, 둘의 부모를 반환
  return P[0][u];
}

void dfs(int cur){
  // cur vertex와 연결되어 있는 정점 nxt를 가져옴
  for(int nxt : adj[cur]){
    // 이미 방문한 정점인 경우 아무것도 하지않고 넘어간다.
    if(chk[nxt]) continue;
    // nxt vertex를 방문했다는 표식을 남김
    chk[nxt] = 1;
    // nxt vertex의 depth 정보 갱신
    dep[nxt] = dep[cur] + 1;
    // nxt의 2^0번째 조상은 cur
    P[0][nxt] = cur;
    
    // nxt vertex의 child로 깊이 우선 탐색
    dfs(nxt);
  }
}
int main() {
  // fastio
  cin.tie(0)->sync_with_stdio(0);
  
  // numbers of tree's vertex
  cin >> n;

  // edge mapping
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  // 1의 2^0번째 조상은 없음( root vertex )
  P[0][1] = -1;

  // root vertex의 깊이는 1
  dep[1] = 1; 

  // root vertex 방문 완료
  chk[1] = 1;

  // dfs로 각 정점 깊이 정보와 위 조상 정보 mapping 
  dfs(1);

  // sparse table 초기화
  // index가 음수로 들어가지 않게 처리해야함
  for(int i = 1; i < MXK; i++){
    for(int j = 1; j <= n; j++){
      int mid = P[i-1][j];
      P[i][j] = (mid == -1) ? -1 : P[i-1][mid];
    }
  }
  // 쿼리 개수 입력
  cin >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << nl;
  }
}