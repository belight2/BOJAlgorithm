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

int n, m, k;
vector<vi> adj;
vi dist;

int main() {
    fastio(nullptr, false);

    cin >> n >> k >> m;

    vector<vi>(n + m + 1).swap(adj);
    vi(n + m + 1, -1).swap(dist);

    for(int u = n + 1; u <= n + m; u++) {
        int v{};
        for(int i = 0; i < k; i++) {
            cin >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    qi q;
    dist[1] = 1;
    q.push(1);

    while(sz(q)) {
        auto cur = q.front(); q.pop();
        
        for(auto nxt : adj[cur]) {
            if(dist[nxt] == -1) {
                dist[nxt] = dist[cur] + (nxt <= n);
                q.push(nxt);
            }
        }
    }

    cout << dist[n];
}