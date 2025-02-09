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
vi adj[10'005];
vi villager(10'005);

int d[10'005][2];
bool vis[10'005];

void dfs(int cur) {
    d[cur][0] = 0;
    d[cur][1] = villager[cur];

    vis[cur] = 1;

    for(auto nxt : adj[cur]) {
        if(vis[nxt]) {
            continue;
        }

        dfs(nxt);

        d[cur][0] += max(d[nxt][0], d[nxt][1]);
        d[cur][1] += d[nxt][0];
    }
}

int main() {
    fastio(nullptr, false);
    memset(d, -1, sizeof(d));

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> villager[i];
    }

    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(1);

    cout << max(d[1][0], d[1][1]);
}