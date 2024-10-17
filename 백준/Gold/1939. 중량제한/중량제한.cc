// Authored by : chjh2129
#include <bits/stdc++.h>
/*
  간선 정보를 가중치가 큰 순서부터 순차적으로 merge를 진행하여 풀이합니다.

  임의의 간선 (w, u, v)가 merge가 되고 출발지(st)와 목적지(en)가 같은 집합에 속하게되었다면.

  이전에 연결된 간선의 가중치는 w보다 크거나 같습니다. 이후에 연결할 간선 정보는 w보다 작거나 같으므로,

  출발지에서 목적지로 들고갈 수 있는 중량의 최댓값은 w가 됩니다.
*/
using namespace std;
using ti = tuple<int, int, int>;

int n, m; // 정점과 간선의 개수
vector<ti> edges; // 간선 정보

vector<int> p(10005, -1);

int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(p[x] == p[y]) p[x]--;
  if(p[x] > p[y]) swap(x, y);
  p[y] = x;
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input  
  cin >> n >> m;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }
  int st, en; // 출발지와 목적지
  cin >> st >> en;
  
  // solve
  int ans{};
  sort(edges.rbegin(), edges.rend()); // 내림차순 정렬
  for(auto &[w, u, v] : edges){
    merge(u, v);
    if(find(st) == find(en)){
      ans = w;
      break;
    }
  }

  // output
  cout << ans;  
}