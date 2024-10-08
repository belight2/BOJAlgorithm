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

int n; // |str|
string str;
bool ispalindrome[2501][2501];
int d[2501][2501];

int solve(int st, int en){
  if(d[st][en] != -1) return d[st][en];
  if(ispalindrome[st][en]) return d[st][en] = 1;

  int ans = 3000;
  for(int mid = st; mid < en; mid++){
    if(ispalindrome[st][mid]) ans = min(ans, 1 + solve(mid+1, en));
  }
  return d[st][en] = ans;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> str;

  // init
  n = sz(str); // n is |str|
  ispalindrome[0][0] = 1;
  ispalindrome[n-1][n-1] = 1;
  if(str[0] == str[1]) ispalindrome[0][1] = 1;
  if(str[n-1] == str[n-2]) ispalindrome[n-2][n-1] = 1;
  
  // solve
  for(int i = 1; i < n-1; i++){
    ispalindrome[i][i] = 1; // 자기자신은 항상 palindrome

    int st = i - 1;
    int en = i + 1;
    while(st >= 0 && en < n && str[st] == str[en] && ispalindrome[st+1][en-1]) ispalindrome[st--][en++] = 1;
    if(str[i] == str[i+1]){
      ispalindrome[i][i+1] = 1;
      st = i - 1;
      en = i + 2;
      while(st >= 0 && en < n && str[st] == str[en] && ispalindrome[st+1][en-1]) ispalindrome[st--][en++] = 1;
    }
  }

  // output
  memset(d, -1, sizeof(d)); 
  cout << solve(0, n-1);
}