#include <bits/stdc++.h>

using namespace std;

using ti = tuple<int,int,int>;

const int dx[6] = { 0, 0, 1, 1, 2, 2 };
const int dy[6] = { 1, 2, 0, 2, 0, 1 };

int bucket[3];
bool vis[205][205];
vector<int> ans;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> bucket[0] >> bucket[1] >> bucket[2];  
  
  ans.push_back(bucket[2]);
  
  queue<ti> q;
  q.push({0, 0, bucket[2]});
  vis[0][0] = 1;
  
  while(q.size()){
    auto [a, b, c] = q.front(); q.pop();
    for(int i = 0; i < 6; i++){
      int nxt[]{a, b, c};
      int cx = dx[i];
      int nx = dy[i];
      
      int remain = max(0, (nxt[cx]+nxt[nx])-bucket[nx]);
      nxt[nx] = (remain ? bucket[nx] : nxt[cx]+nxt[nx]);
      nxt[cx] = remain;

      if(vis[nxt[0]][nxt[1]]) continue;
      if(nxt[0] == 0) ans.push_back(nxt[2]);
      
      vis[nxt[0]][nxt[1]] = 1;
      q.push({nxt[0], nxt[1], nxt[2]});
    } 
  }

  sort(ans.begin(), ans.end());
  auto endit = unique(ans.begin(), ans.end());
  for(auto it = ans.begin(); it < endit; it++) cout << *it << ' ';
}