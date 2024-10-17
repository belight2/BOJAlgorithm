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

string s;
int chk[26], cnt[10];
string num[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

// k에 해당하는 알파벳이 cnt개 이상 있는지 검사
bool isexist(const string &k, int cnt){
  for(char c : k)
    if(chk[c - 'A'] <= cnt) return 0;
  return 1;
}

bool func(int k, string &ans){
  // base conditon
  if(k == 10){
    for(int i = 0; i < 26; i++) 
      if(chk[i]) return 0;
    return 1;
  }

  // body
  for(int i = 1; i <= cnt[k]; i++){
    for(char &c : num[k]) chk[c - 'A'] -= 1;
    ans.pb(k + '0');
    if(func(k+1, ans)) return 1;
  }

  // 숫자 k를 추가하지 않는다.
  for(char &c : num[k]) chk[c - 'A'] += cnt[k];
  for(int i = 0; i < cnt[k]; i++) ans.pop_back();
  
  return func(k+1, ans);
}

string solve(){
  // input
  cin >> s;
  
  // init
  memset(chk, 0, sizeof(chk));
  memset(cnt, 0, sizeof(cnt));
  for(char c : s) chk[c - 'A']++;

  for(int i = 0; i < 10; i++){
    while(isexist(num[i], cnt[i])) cnt[i]++;
  }

  string ans{};
  func(0, ans);
  return ans;  
}

int main() {
  fastio(nullptr, false);
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) cout << "Case #" << i << ": " << solve() << nl;
}