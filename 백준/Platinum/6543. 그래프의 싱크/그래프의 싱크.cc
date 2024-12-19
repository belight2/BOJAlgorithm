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
vi adj[5'005], xadj[5'005];
int scc[5'005];

stack<int> stk;

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

int kosaraju() {
    memset(scc, -1, sizeof(scc));
    for(int cur = 1; cur <= n; cur++) {
        if(scc[cur] == -1) {
            dfs(cur, -1);
        }
    }

    int scc_num{};
    memset(scc, -1, sizeof(scc));
    while(sz(stk)) {
        auto cur = stk.top(); stk.pop();

        if(scc[cur] == -1) {
            dfs(cur, scc_num++);
        }
    }

    return scc_num;
}

void solve() {
    for(int i = 1; i <= n; i++) {
        vi ().swap(adj[i]);
        vi ().swap(xadj[i]);
    }
    
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        xadj[v].pb(u);
    }

    int scc_count = kosaraju();
    vi outdeg(scc_count);

    for(int cur = 1; cur <= n; cur++) {
        for(auto nxt : adj[cur]) {
            if(scc[nxt] == scc[cur]) continue;
            outdeg[scc[cur]]++;
        }
    }

    for(int cur = 1; cur <= n; cur++) {
        if(outdeg[scc[cur]] == 0) {
            cout << cur << ' ';
        }
    } 
    cout << nl;
}

int main() {
    fastio(nullptr, false);
    
    while(cin >> n, n) {
        cin >> m;
        solve();
    }
}