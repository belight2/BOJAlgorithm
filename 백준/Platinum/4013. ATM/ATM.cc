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
vi adj[500'005], xadj[500'005];

stack<int> stk;

int scc[500'005];

int st, p;
int atm[500'005];

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
    while(!stk.empty()) {
        auto cur = stk.top(); stk.pop();

        if(scc[cur] == -1) {
            dfs(cur, scc_num++);
        }
    }

    return scc_num;
}

int main() {
    fastio(nullptr, false);
    
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        xadj[v].pb(u);
    }

    for(int i = 1; i <= n; i++) {
        cin >> atm[i];
    }
    
    int scc_count = kosaraju();

    vector<vi> scc_adj(scc_count);
    vi scc_atm(scc_count);
    vi d(scc_count);

    // scc간 edge 추출
    for(int cur = 1; cur <= n; cur++) {
        scc_atm[scc[cur]] += atm[cur];
        for(auto nxt : adj[cur]) {
            if(scc[cur] == scc[nxt]) continue;
            scc_adj[scc[cur]].pb(scc[nxt]);
        }
    }

    cin >> st >> p;

    vi curry(p);
    for(auto &x : curry) {
        cin >> x;
    }

    queue<int> q; 
    st = scc[st];
    d[st] = scc_atm[st];
    q.push(st);
    while(sz(q)) {
        auto cur = q.front(); q.pop();
        for(auto nxt : scc_adj[cur]) {
            if(d[nxt] < d[cur] + scc_atm[nxt]) {
                q.push(nxt);
                d[nxt] = d[cur] + scc_atm[nxt];
            }
        }
    }

    int ans{};
    for(auto x : curry) {
        ans = max(ans, d[scc[x]]);
    }
    cout << ans;
}