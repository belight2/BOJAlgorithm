#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb; typedef queue<int> qi; typedef queue<ll> ql;
typedef queue<pi> qpi; typedef queue<pl> qpl; typedef queue<ti> qti; typedef queue<tl> qtl;
#define X first
#define Y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const char nl = '\n';
int state, m, x;
string cmd;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> m;
  while(m--){
    cin >> cmd;
    if(cmd == "add"){
      cin >> x;
      state |= (1 << (x-1));
    }
    else if(cmd == "remove"){
      cin >> x;
      state &= ~(1 << (x-1));
    }
    else if(cmd == "check"){
      cin >> x;
      cout << ((state >> (x-1)) & 1) << nl;
    }
    else if(cmd == "toggle"){
      cin >> x;
      state ^= (1 << (x-1));
    }
    else if(cmd == "all"){
      state = 0xfffff;
    }
    else{
      state = 0;
    }
  }
}