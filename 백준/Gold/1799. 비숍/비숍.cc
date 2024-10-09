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
bool diag1[20], diag2[20];
vpi white, black;
int white_ans, black_ans;

void select(int k, int depth, int mode){
  (mode ? white_ans : black_ans) = max((mode ? white_ans : black_ans), depth);

  if(k == sz((mode ? white : black)) || depth == sz((mode ? white : black))) return;
  
  for(int i = k; i < sz((mode ? white : black)); i++){
    auto &[x, y] = (mode ? white : black)[i];
    if(!diag1[x+y] && !diag2[y - x + n - 1]){
      diag1[x + y] = 1;
      diag2[y - x + n - 1] = 1;
      select(i+1, depth+1, mode);
      diag1[x + y] = 0;
      diag2[y - x + n - 1] = 0;
    }
  }
}

int main() {
  fastio(nullptr, false);
  
  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    int available;
    for(int j = 0; j < n; j++){
      cin >> available;
      if(!available) continue;
      ((i+j)&1) ? white.pb({i, j}) : black.pb({i, j});
    }
  }

  // solve
  select(0, 0, 0);
  select(0, 0, 1);

  // output
  cout << white_ans + black_ans;
}