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

int n, m, st, en;
vi adj[10'005], xadj[10'005];
int scc[10'005];

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

int main() {
    fastio(nullptr, false);

    cin >> n >> m >> st >> en;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        xadj[v].pb(u);
    }

    int scc_count = kosaraju();

    vector<vi> scc_adj(scc_count);
    vi d(scc_count);
    vi sc(scc_count);
    for(int cur = 1; cur <= n; cur++) {
        sc[scc[cur]]++;
        for(auto nxt : adj[cur]) {
            if(scc[cur] == scc[nxt]) continue;
            scc_adj[scc[cur]].pb(scc[nxt]);
        }
    }

    queue<int> q;
    q.push(scc[st]);
    d[scc[st]] = sc[scc[st]];
    while(sz(q)) {
        auto cur = q.front(); q.pop();
        for(auto nxt : scc_adj[cur]) {
            if(d[nxt] < d[cur] + sc[nxt]) {
                d[nxt] = d[cur] + sc[nxt];
                q.push(nxt);
            }
        }
    }

    cout << d[scc[en]];
}