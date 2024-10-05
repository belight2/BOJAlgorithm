#include <bits/stdc++.h>

using namespace std;


int slen, plen; // |S|, |P|
int cnt[26];
string DNA;

bool is_password(){ return (cnt['A'-'A'] <= 0)&&(cnt['C'-'A'] <= 0)&&(cnt['G'-'A'] <= 0)&&(cnt['T'-'A'] <= 0); }
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> slen >> plen;
  cin >> DNA;  
  cin >> cnt['A'-'A'] >> cnt['C'-'A'] >> cnt['G'-'A'] >> cnt['T'-'A'];

  int ans{};
  deque<int> dq;

  for(int i = 0; i < slen; i++){
    dq.push_back(i);
    cnt[DNA[i] - 'A']--;
    
    if(dq.size() < plen) continue;
    if(is_password()) ans++;

    char cur = DNA[dq.front()];
    dq.pop_front();
    cnt[cur-'A']++;
  }
  cout << ans;
}