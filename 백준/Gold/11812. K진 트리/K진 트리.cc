#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pi; typedef pair<ll, ll> pl;
typedef tuple<int, int, int> ti; typedef tuple<ll, ll, ll> tl; typedef vector<int> vi; typedef vector<ll> vl;
typedef vector<pi> vpi; typedef vector<pl> vpl; typedef vector<ti> vti; typedef vector<tl> vtl;
typedef vector<string> vs; typedef vector<bool> vb;
#define X first
#define Y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const char nl = '\n';
int k, q;
ll n, x, y;

ll cal_depth(ll vtx){
  ll dif = k - 2, depth = 0;
  while(vtx > 1){
    vtx = (vtx+dif) / ll(k);
    depth++;
  }
  return depth;
}

ll up(ll vtx, ll count){
  ll dif = k - 2;
  while(count--){
    vtx = (vtx+dif) / ll(k);
  }
  return vtx;
}

ll calculate_distance(ll left, ll right){
  if(k == 1) return abs(left - right);
  
  ll left_depth = cal_depth(left);
  ll right_depth = cal_depth(right);
  ll distance{};
  if(left_depth < right_depth){
    distance = right_depth - left_depth;
    right = up(right, right_depth - left_depth);
  }
  else if(left_depth > right_depth){
    distance = left_depth - right_depth;
    left = up(left, left_depth - right_depth);
  }
  if(left == right) return distance;
  ll dif = k - 2;
  while(left != right){
    left = (left+dif) / ll(k);
    right = (right+dif) / ll(k);
    distance += 2;
  }
  return distance;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> q;
  while(q--){
    cin >> x >> y;
    cout << calculate_distance(x, y) << nl;
  }
}