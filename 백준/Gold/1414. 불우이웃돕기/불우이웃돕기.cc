#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define fastio(x, y) cin.tie((x))->sync_with_stdio((y))
#define X first
#define Y second
#define pb push_back
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';

int n;
vti edges; // 간선 정보

vi p(55, -1); // p[x] < 0인 노드 x가 루트노드

// 좌표 압축을 진행하면서 노드 x의 루트 노드를 반환
int find(int x){ return (p[x] < 0 ? x : p[x] = find(p[x])); }

/*
  두 노드의 merge가 성공했으면 true, 실패하면 false 반환
*/
bool merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return 0;
  // union by rank
  if(p[x] == p[y]) p[x]--;
  if(p[x] > p[y]) swap(x, y);
  p[y] = x; 
  return 1;
}

// 알파벳이 소문자면 1 ~ 26, 대문자면 27 ~ 52, 각 숫자는 알파벳 순서대로 증가함.
int convert(char c){
  return (islower(c) ? c - 'a' + 1 : c - 'A' + 27);
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int i = 1; i <= n; i++){
    char weight; // 랜선의 길이(가중치)
    for(int j = 1; j <= n; j++){
      cin >> weight;     
      if(weight == '0') continue;
      edges.pb({convert(weight), i, j});
    }
  }

  sort(all(edges)); // 정렬

  int ans{}; // 봉사할 랜선 길이의 총합
  int cnt{}; // 연결에 성공한 간선의 개수
  for(auto &[w, u, v] : edges){
    if(cnt == n-1 || !merge(u, v)){
      ans += w;
      continue;
    }
    // merge에 성공
    cnt++;
  }

  // output
  cout << (cnt == n-1 ? ans : -1);
}