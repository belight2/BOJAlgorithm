#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#define X first
#define Y second

using namespace std;
const char nl = '\n';
unordered_map<string, int> word;
int n, m, k;
int a[13][13];
string str[1005];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string curS;

pair<int, int> getIdx(int x){
  return {x / 100, x % 100};
}
void mapping(){
  for(int i = 0; i <= n+1; i++){
    for(int j = 0; j <= m+1; j++){
      int row = (i + n) % n;
      int col = (j + m) % m;
      row = ( row == 0 ) ? n : row;
      col = ( col == 0 ) ? m : col;
      a[i][j] = row*100 + col;
    }
  }
}
void back_tracking(int x, int y, int cnt){
  if(cnt == 6){
    if(word.find(curS) != word.end()) word[curS]++;
    return;
  }
  if(word.find(curS) != word.end()) word[curS]++;
  for(int dir = 0; dir < 8; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 1 || nx > n || ny < 1 || ny > m) tie(nx, ny) = getIdx(a[nx][ny]);
    curS.push_back((char)a[nx][ny]);
    back_tracking(nx, ny, cnt+1);
    curS.pop_back();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  mapping();
  for(int i = 1; i <= n; i++){
    string s; cin >> s;
    for(int j = 1; j <= m; j++){
      a[i][j] = s[j-1];
    }
  }
  for(int i = 0; i < k; i++){
    string s; cin >> s;
    str[i] = s;
    word[s] = 0;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      curS.push_back((char)a[i][j]);
      back_tracking(i, j, 1);
      curS.pop_back();
    }
  }
  for(int i = 0; i < k; i++) cout << word[str[i]] << nl;
}