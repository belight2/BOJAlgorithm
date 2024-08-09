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

 
string DNA;
int d[505][505];

bool is_dna(int x, int y, char a, char b) { return DNA[x] == a && DNA[y] == b; }

int solve(int st, int en){
  if(st >= en) return 0;
  if(d[st][en] != -1) return d[st][en];
  for(int k = st; k < en; k++){
    d[st][en] = max(d[st][en], solve(st, k) + solve(k+1, en));
  }
  if(is_dna(st, en, 'a', 't') || is_dna(st, en, 'g', 'c')) d[st][en] = max(d[st][en], 2 + solve(st+1, en-1));
  return d[st][en];
}

int main() {
  fastio(nullptr, false);
  cin >> DNA;
  memset(d, -1, sizeof(d));
  cout << solve(0, sz(DNA)-1);
}