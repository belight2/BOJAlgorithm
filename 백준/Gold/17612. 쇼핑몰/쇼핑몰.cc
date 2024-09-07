// Authored by : chjh2129
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;
typedef pair<ll, ll> pll;
#define X first
#define Y second

class cmp{
  public:
    bool operator()(const tll &a, const tll &b){
      auto [ax, ay, az] = a;
      auto [bx, by, bz] = b;
      return ((ax == bx) ? (ay < by) : (ax > bx));
    }
};

int n, k;
priority_queue<pll, vector<pll>, greater<pll>> tot;
priority_queue<tll, vector<tll>, cmp> pq;

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);

  // input
  cin >> n >> k;
  for(int i = 1; i <= k; i++) tot.push({0, i});

  // init
  ll ID, w; // 아이디, 물건 개수
  while(n--){
    cin >> ID >> w;
    auto [c_time, c_num] = tot.top(); tot.pop(); // 카운터의 총 시간과 카운터 번호
    tot.push({c_time + w, c_num});
    pq.push({c_time+w, c_num, ID});
  }

  // solve
  ll ans{}, cnt = 1;
  while(!pq.empty()){
    /*
     앞에 두 값은 문제의 조건을 맞추기 위해 정렬 요소들로 사용한 데이터임
     실제로 필요한건 고객의 아이디이므로 나머지는 버린다.
    */
    auto [_, __, ID] = pq.top(); pq.pop(); 
    ans += ID * cnt++;
  }

  // output
  cout << ans;
}