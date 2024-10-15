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

const string arrow = " => ";
const int offset = 26;
const int INF = 0x3f3f3f3f;

int n; // 간선의 개수
int adj[55][55];

// 알파벳을 인덱스 정보로 반환
int convert(char c){ return (isupper(c) ? c - 'A' : c - 'a' + offset); } 
char getvertex(int x){ return (x < 26 ? x + 'A' : x - offset + 'a'); }

int main() {
  fastio(nullptr, false);

  // init
  memset(adj, 0x3f, sizeof(adj));
  for(int i = 0; i < 2 * offset; i++) adj[i][i] = 0;

  // input
  cin >> n;  
  while(n--){
    string tmp;
    char u, v;
    cin >> u >> tmp >> v;
    adj[convert(u)][convert(v)] = 1;
  }

  // solve
  for(int k = 0; k < 2*offset; k++){
    for(int i = 0; i < 2*offset; i++){
      for(int j = 0; j < 2*offset; j++){
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }

  vector<pair<char, char>> ans;
  for(int i = 0; i < 2 * offset; i++){
    for(int j = 0; j < 2 * offset; j++){
      if(adj[i][j] == INF || i == j ) continue;
      ans.pb({getvertex(i), getvertex(j)});      
    } 
  }

  // output
  cout << sz(ans) << nl;
  for(auto &[src, dst] : ans){
    cout << src << arrow << dst << nl;
  }
}