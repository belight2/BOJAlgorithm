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

int n;
int f[10];

bool chk(){
  int ret{};
  for(int i = 0; i < 10; i++) if(f[i]) ret++;
  return ret <= 2;
}

int main() {
  fastio(nullptr, false);
  
  cin >> n;

  vector<int> a(n);
  for(auto &x : a) cin >> x;

  int ans{}, en{};
  for(int st = 0; st < n; st++){
    while(en < n && chk()) f[a[en++]]++;
    ans = max(ans, (chk() ? en-st : en-st-1));
    f[a[st]]--;
  }
  cout << ans;
}