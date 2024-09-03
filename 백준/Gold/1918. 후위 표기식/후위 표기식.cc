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

string line;
stack<char> stk;

int isop(char c){
  if(c == '+' || c == '-') return 1;
  if(c == '*' || c == '/') return 2;
  return 0;
}

int main() {
  fastio(nullptr, false);
  
  cin >> line;

  string ans{};
  for(auto& c : line){
    if(c == '(') stk.push(c);
    else if(c == ')'){
      while(sz(stk) && stk.top() != '('){
        ans += stk.top();
        stk.pop();
      }
      stk.pop();
    }
    else if(isop(c) == 0) ans += c;
    else if(stk.empty()) stk.push(c);
    else if(isop(c) == 1){
      while(sz(stk) && stk.top() != '('){
        ans += stk.top();
        stk.pop();
      }
      stk.push(c);
    }
    else if(isop(c) == 2){
      while(sz(stk) && ( isop(stk.top()) == 2)){
        ans += stk.top();
        stk.pop();
      } 
      stk.push(c);
    }
  }
  while(sz(stk)){
    ans += stk.top();
    stk.pop();
  }
  cout << ans;
}