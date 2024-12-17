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
vector<int> adj[100'005], xadj[100'005];
stack<int> stk;

int scc[100'005];
bool indeg[100'005];

void dfs(int cur, int scc_num) {
    scc[cur] = scc_num == -1 ? 0 : scc_num;

    for(auto nxt : scc_num == -1 ? adj[cur] : xadj[cur]) {
        if(scc[nxt] == -1) {
            dfs(nxt, scc_num);
        }
    } 

    if(scc_num == -1) {
        stk.push(cur);
    }
}

void solve(int tc) {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        vi ().swap(adj[i]);
        vi ().swap(xadj[i]);
    }
    memset(scc, -1, sizeof(scc));
    memset(indeg, 0, sizeof(indeg));

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        xadj[v].push_back(u);
    }

    for(int cur = 1; cur <= n; cur++) {
        if(scc[cur] == -1) {
            dfs(cur, -1);
        }
    }

    int scc_num{};
    memset(scc, -1, sizeof(scc));
    while(!stk.empty()) {
        auto cur = stk.top(); stk.pop();
        if(scc[cur] == -1) {
            dfs(cur, scc_num++);
        }
    }

    int ans = scc_num;
    for(int cur = 1; cur <= n; cur++) {
        for(auto nxt : adj[cur]) {
            if(scc[cur] == scc[nxt] || indeg[scc[nxt]]) continue;
            indeg[scc[nxt]] = 1;
            ans--;
        }
    }      

    cout << ans << nl;
}

int main() {
    fastio(nullptr, false);
    int tc{};
    cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}