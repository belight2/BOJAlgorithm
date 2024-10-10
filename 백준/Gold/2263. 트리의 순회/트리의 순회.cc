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
int idx[100'005];
int postorder[100'005];

// 트리 
int l[100'005];
int r[100'005];

void find_tree(int ist, int ien, int pst, int pen, int cur){
  int k = idx[cur];
  int ls = k - ist, rs = ien - k;

  if(ls > 0){
    l[cur] = postorder[pst+ls-1];
    if(ls > 1) find_tree(ist, k-1, pst, pst+ls-2, l[cur]);
  }
  if(rs > 0){
    r[cur] = postorder[pen];
    if(rs > 1) find_tree(k+1, ien, pst+ls, pen-1, r[cur]);
  }
}

void preorder(int cur){
  if(cur == 0) return;
  cout << cur << ' ';
  preorder(l[cur]);
  preorder(r[cur]);  
}

int main() {
  fastio(nullptr, false);

  // input
  cin >> n;
  for(int i = 1; i <= n; i++){
    int node;
    cin >> node;
    idx[node] = i; // inorder는 순서값만 저장
  }

  for(int i = 1; i <= n; i++) cin >> postorder[i];

  // solve
  find_tree(1, n, 1, n-1, postorder[n]);

  // output
  preorder(postorder[n]);
}