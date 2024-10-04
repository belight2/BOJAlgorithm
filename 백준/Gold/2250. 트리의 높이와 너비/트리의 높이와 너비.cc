#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;
const char nl = '\n';
int n;
int l[10001], r[10001], root;
pair<int,int> Col[10001];
int col;
void inorder(int cur, int dep){
  if(cur == -1) return;
  inorder(l[cur], dep+1);
  col++;
  Col[dep].X = ( !Col[dep].X || Col[dep].X > col ) ? col : Col[dep].X;
  Col[dep].Y = ( !Col[dep].X || Col[dep].Y < col ) ? col : Col[dep].Y; 
  inorder(r[cur], dep+1);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<bool> isRoot(n+1, true);
  for(int i = 1; i <= n; i++){
    int p, ln, rn;
    cin >> p >> ln >> rn;
    l[p] = ln;
    r[p] = rn;
    if(ln != -1) isRoot[ln] = 0;
    if(rn != -1) isRoot[rn] = 0;
  }
  for(int i = 1; i <= n; i++) if(isRoot[i]) { root = i; break; }
  inorder(root, 1);
  int depth = 0, width = 0; 
  for(int i = 1; i <= n; i++){
    if(Col[i].X == 0 && Col[i].Y == 0) break;
    int tmp = Col[i].Y - Col[i].X + 1;
    if(width < tmp){
      depth = i;
      width = tmp;
    }
  }
  cout << depth << ' ' << width;
}