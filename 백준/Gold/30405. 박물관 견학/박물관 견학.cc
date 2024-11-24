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
vi pos;

int main() {
  fastio(nullptr, false);

  cin >> n >> m;
  while(n--){
    int k; cin >> k;
    // 각 아기 고양이의 출발점과 끝점 전시관 번호만 저장
    for(int i = 0; i < k; i++){
      int x; cin >> x;
      if(i != 0 && i != k - 1) continue;
      pos.pb(x);
    }
  }

  sort(all(pos));

  cout << pos[(sz(pos) >> 1) - 1];
}