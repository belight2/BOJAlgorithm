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

int n, m;

vi idx(100005);

int find_gate(int x){
  if(x == 0 || idx[x] == x) return x;
  return idx[x] = find_gate(idx[x]);
}

int main() {
  fastio(nullptr, false);
  
  // init
  iota(all(idx), 0);

  // input
  cin >> n >> m;

  // solve
  int ans{};
  while(m--){
    int gate;
    cin >> gate;
    gate = find_gate(gate);
    if(!gate) break;
    idx[gate]--;
    ans++;
  }
  
  // output
  cout << ans;
}