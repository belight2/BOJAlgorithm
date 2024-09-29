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

int idx[1'000'001];
int card[100'005];
int score[100'005];

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> card[i];
    idx[card[i]] = i;
  }

  // solve
  int limit = *max_element(card, card+n+1);
  for(int i = 1; i <= n; i++){
    for(int j = card[i] + card[i]; j <= limit; j += card[i]) {
      if(!idx[j]) continue;
      // i가 이김
      score[i]++;
      score[idx[j]]--;
    } 
  }
  
  // output
  for(int i = 1; i <= n; i++) cout << score[i] << ' ';
}