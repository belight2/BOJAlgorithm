// Authored by : chjh2129
#include <bits/stdc++.h>

using namespace std;

// namespace 형태로 구현해보겠음

namespace trie {
  const int root = 1;
  const int mx = 1'000'005;
  int unused = root + 1;
  int chk[mx];
  int nxt[mx][26];

  void init(){ memset(nxt, -1, sizeof(nxt)); }

  int idx(char c){ return c - 'a'; }

  // 삽입을 하고, 별칭을 반환
  string insert(string &s){
    bool flag{};
    string ret{};
    int cur = root;

    for(auto c : s){
      if(nxt[cur][idx(c)] == -1){
        nxt[cur][idx(c)] = unused++;
        if(!flag) ret.push_back(c);
        flag = 1;
      }
      if(!flag) ret.push_back(c);
      cur = nxt[cur][idx(c)];
    }

    chk[cur]++;
    if(!flag && chk[cur] != 1) ret += to_string(chk[cur]);
    
    return ret;
  }
}

int n;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // init
  trie::init();

  cin >> n;
  while(n--){
    string str;
    cin >> str;

    cout << trie::insert(str) << '\n';
  }
}