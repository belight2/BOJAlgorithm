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

int n, cnt;
int a[10'005], b[10'005];

bool bubble_sort(){
  for(int i = n - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      if(a[j] > a[j + 1]){
        cnt -= a[j] != b[j];
        cnt -= a[j+1] != b[j+1];
        swap(a[j], a[j+1]);
        cnt += a[j] != b[j];
        cnt += a[j+1] != b[j+1];
      }
      if(cnt == 0) return 1;
    }
  }
  return 0;
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  
  for(int i = 0; i < n; i++){
    cin >> b[i];
    if(a[i] != b[i]) cnt++;
  }

  cout << (cnt == 0 ? 1 : bubble_sort()); 
}