#include <iostream>
using namespace std;
const char nl = '\n';
int n;
int lc[28];
int rc[28];
void preorder(int cur){
  cout << (char)(cur + 'A');
  if(lc[cur]) preorder(lc[cur]);
  if(rc[cur]) preorder(rc[cur]);
}
void inorder(int cur){
  if(lc[cur]) inorder(lc[cur]);
  cout << (char)(cur + 'A');
  if(rc[cur]) inorder(rc[cur]);
}
void postorder(int cur){
  if(lc[cur]) postorder(lc[cur]);
  if(rc[cur]) postorder(rc[cur]);
  cout << (char)(cur + 'A'); 
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  char p, l, r;
  while(n--){
    cin >> p >> l >> r;
    if(l != '.') lc[p-'A'] = l - 'A';
    if(r != '.') rc[p-'A'] = r - 'A';
  }
  preorder(0);
  cout << nl;
  inorder(0);
  cout << nl;
  postorder(0);
}