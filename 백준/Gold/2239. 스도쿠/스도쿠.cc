#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int num[10][10];
bool isrow[9][10];
bool iscol[9][10];
bool isblock[9][10];
int threshold;
bool flag = false;
vpi pos;

void func(int k){
  if(k == threshold){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cout << num[i][j];
      }
      cout << nl;
    }
    flag = true;
    return;
  }
  auto &[x, y] = pos[k];
  for(int n = 1; n <= 9; n++){     
    if(isrow[x][n] || iscol[y][n] || isblock[(x/3)*3+(y/3)][n]) continue;
    num[x][y] = n;                 
    isrow[x][n] = 1;               
    iscol[y][n] = 1;               
    isblock[(x/3)*3+(y/3)][n] = 1; 
    func(k+1);                     
    if(flag) return;               
    isrow[x][n] = 0;               
    iscol[y][n] = 0;
    isblock[(x/3)*3+(y/3)][n] = 0; 
  } 
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 9; i++){
    string str;
    cin >> str;
    for(int j = 0; j < 9; j++){
      num[i][j] = str[j] - '0';
      if(num[i][j] != 0){
        isblock[(i/3)*3+(j/3)][num[i][j]] = 1;
        isrow[i][num[i][j]] = 1;
        iscol[j][num[i][j]] = 1;
      }
      else pos.pb({i, j});
    }
  }
  threshold = pos.size();
//#define DEBUG_
#ifndef DEBUG_
  func(0);
#endif
}