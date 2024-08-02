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

const int root = 1;
const int mx = 1'000'005;

int unused = 2;
bool chk[mx];
int nxt[mx][2];

int n;
bool flag;
string ret_str;

int ctoi(char c){ return c - '0'; }

void insert(string &s){
  int cur = root;
  for(auto c : s){
    if(nxt[cur][ctoi(c)] == -1) nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
  }
  chk[cur] = 1;
}

bool find(string &s){
  int cur = root;
  for(auto c : s){
    if(nxt[cur][ctoi(c)] == -1) return 0;
    cur = nxt[cur][ctoi(c)];
  }
  return chk[cur];
}

void dfs(int len, string s){
  if(flag) return;
  if(sz(s) == len){
    insert(s);
    flag = 1;
    ret_str = s;
  }
  string a = s + '0';
  if(!find(a)) dfs(len, a);
  if(flag) return;
  string b = s + '1';
  if(!find(b)) dfs(len, b);
  return;
}

int main() {
  fastio(nullptr, false);
  memset(nxt, -1, sizeof(nxt));
  cin >> n;
  vpi a(n);
  vs ans(n);
  for(int i = 0; i < n; i++){
    cin >> a[i].X;
    a[i].Y = i;
  }
  sort(all(a));
  for(int i = 0; i < n; i++){
    auto [len, idx] = a[i];
    flag = 0;
    dfs(len, "");
    if(!flag){
      cout << "-1\n";
      return 0;
    }
    ans[idx] = ret_str;
  }
  cout << "1\n";
  for(int i = 0; i < n; i++) cout << ans[i] << nl;
}