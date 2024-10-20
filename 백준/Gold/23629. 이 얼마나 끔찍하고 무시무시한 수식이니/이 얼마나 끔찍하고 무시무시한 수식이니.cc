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

unordered_map<string, int> s2c = {
  {"ZERO", '0'}, {"ONE", '1'},
  {"TWO", '2'}, {"THREE", '3'},
  {"FOUR", '4'}, {"FIVE", '5'},
  {"SIX", '6'}, {"SEVEN", '7'},
  {"EIGHT", '8'}, {"NINE", '9'}
};

unordered_map<int, string> c2s = {
  {'0', "ZERO"}, {'1', "ONE"},
  {'2', "TWO"}, {'3', "THREE"},
  {'4', "FOUR"}, {'5', "FIVE"},
  {'6', "SIX"}, {'7', "SEVEN"},
  {'8', "EIGHT"}, {'9', "NINE"}
};

ll a, b;
string str;
vector<ll> numberList;
vector<char> opList;
string left_side;

bool isoperate(char cur){  return cur == '+' || cur == '-' || cur == '*'; }

bool convert(){
  string cur{}, number{};
  for(int i = 0; i < sz(str); i++){
    if(sz(cur) > 5) return 0;
    if(isupper(str[i])){
      cur.pb(str[i]);
      if(s2c.find(cur) != s2c.end()){
        number.pb(s2c[cur]);
        left_side.pb(s2c[cur]);
        cur = "";
      }
      continue;
    }
    left_side.pb(str[i]);
    if(sz(cur) != 0 || isoperate(str[i-1]) || (str[i] == '=' && i != sz(str) - 1)) return 0;
    opList.pb(str[i]);
    try{
      numberList.pb(stoll(number));
    } catch(const exception e){
      return 0;
    }
    number = "";
  }
  return 1;
}

string number_to_string(ll n){
  string ret = (n < 0) ? "-" : "";
  string tmp = to_string(abs(n));
  for(auto c : tmp) ret += c2s[c];
  return left_side + '\n' + ret;
}

string solve(){
  ll ret = numberList[0];
  for(int i = 1; i < sz(numberList); i++){
    char op = opList[i-1];
    if(op == '+') ret = ret + numberList[i];
    else if(op == 'x') ret = ret * numberList[i];
    else if(op == '-') ret = ret - numberList[i];
    else if(numberList[i] == 0) return "Madness!";
    else ret = ret / numberList[i];
  }

  return number_to_string(ret); 
}

int main() {
  fastio(nullptr, false);
  
  // input
  cin >> str;
  
  // solve
  string ans = "Madness!";
  if(convert()) ans = solve();
  
  // output
  cout << ans;
}