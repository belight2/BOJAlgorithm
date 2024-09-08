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

string line, bomb;
stack<char> stk;

/*
  폭발 문자열이다 : 스택에서 삭제
  폭발 문자열이 아니다 : 스택에 재삽입
*/
void isBomb(){
  stack<char> tmp;
  bool flag{};
  for(int i = sz(bomb)-1; i >= 0; i--){
    if(bomb[i] == stk.top()){
      tmp.push(stk.top());
      stk.pop();
    }
    else{
      flag = 1;
      break;
    } 
  }
  while(flag && sz(tmp)){
    stk.push(tmp.top());
    tmp.pop();
  }
}

int main() {
  fastio(nullptr, false);
  // input
  cin >> line >> bomb;

  // solve
  for(char c : line){
    stk.push(c);
    if(c == bomb[sz(bomb)-1] && sz(stk) >= sz(bomb)) isBomb();
  }

  if(stk.empty()){
    cout << "FRULA";
    return 0;
  }

  string ans{};
  while(sz(stk)){
    ans += stk.top();
    stk.pop();
  }
  reverse(all(ans));
  cout << ans;
}