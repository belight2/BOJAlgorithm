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

int n, m;
vpi a, b;


bool cmp(const pi &a, const pi &b){
  return (a.X == b.X ? a.Y < b.Y : a.X > b.X);
}


int main() {
  fastio(nullptr, false);
  
  // input
  cin >> n;
  for(int i = 0; i < n; i++){
    int val;
    cin >> val;
    a.pb({val, i});
  }

  cin >> m;
  for(int i = 0; i < m; i++){
    int val;
    cin >> val;
    b.pb({val, i});
  }

  // init
  sort(all(a), cmp);
  sort(all(b), cmp);

  // solve
  auto a_it = a.begin();
  auto b_it = b.begin();
  vti ans;
  while(a_it < a.end() || b_it < b.end()){
    auto curA = *a_it;
    auto curB = *b_it;
    if(curA.X == curB.X){
      if(ans.empty() || ( get<1>(ans.back()) < curA.Y && get<2>(ans.back()) < curB.Y)){
        ans.pb({curA.X, curA.Y, curB.Y});
        a_it++; b_it++;
      }
      else{
        if(get<1>(ans.back()) > curA.Y) a_it++;
        if(get<2>(ans.back()) > curB.Y) b_it++;
      }
    }
    else if(curA.X > curB.X) a_it++;
    else b_it++;
  }

  // output
  cout << sz(ans) << nl;
  for(auto &cur : ans){
    cout << get<0>(cur) << ' ';
  }
}