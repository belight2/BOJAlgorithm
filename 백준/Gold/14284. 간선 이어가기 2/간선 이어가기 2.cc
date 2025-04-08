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

const int INF = 0x3f3f3f3f;

int n, m, s, t;
vpi adj[5005];
int d[5005];

int main() {
    fastio(nullptr, false);

    cin >> n >> m;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    cin >> s >> t;
    
    memset(d, 0x3f, sizeof(d));
    priority_queue<pi, vpi, greater<pi>> pq;
    d[s] = 0;
    pq.push({d[s], s});
    while(sz(pq)) {
        auto [cd, cur] = pq.top(); pq.pop();

        if(cd != d[cur]) {
            continue;
        }

        for(auto &[nd, nxt] : adj[cur]) {
            if(d[nxt] > d[cur] + nd) {
                d[nxt] = d[cur] + nd;
                pq.push({d[nxt], nxt});
            }
        }
    }

    cout << d[t];
}