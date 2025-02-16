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
vi adj[1'000'005];
vb leaf_node(1'000'005), chk(1'000'005);

int ans;

bool dfs(int cur, int prv) {
    // 노드 자손들 중 하나라도 리프 노드인지 검사
    bool has_leaf_node = 0;
    for(auto nxt : adj[cur]) {
        if(nxt != prv) {
            has_leaf_node |= dfs(nxt, cur);
        }
    }
    
    // 리프 노드를 가진 노드는 얼리어답터가 되어야 함.
    // 얼리어답터가 된 경우, 부모 노드가 리프 노드가 됨
    if(has_leaf_node) {
        ans++;
        chk[cur] = 1;
        leaf_node[prv] = 1;
    }

    return leaf_node[cur] && !has_leaf_node;
}

int main() {
    fastio(nullptr, false);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for(int i = 1; i <= n; i++) {
        leaf_node[i] = sz(adj[i]) == 1;
    }

    dfs(1, 0);

    cout << ans;
}