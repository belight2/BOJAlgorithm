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

int k, n, m;
vector<vi> adj;
int strahler[1005];

int func(int cur) {
    if(adj[cur].empty()) {
        return strahler[cur] = 1;
    }

    if(strahler[cur] != -1) {
        return strahler[cur];
    }

    int cnt{};
    for(int nxt : adj[cur]) {
        int mx = func(nxt);
        if(strahler[cur] == mx) {
            cnt++;
        }
        if(strahler[cur] < mx) {
            cnt = 1;
            strahler[cur] = mx;
        }
    }

    return (cnt >= 2 ? (strahler[cur] += 1) : strahler[cur]);
}

void solve(int tc) {
    cin >> k >> n >> m;
    
    vector<vi> (n + 1).swap(adj);

    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
    }

    memset(strahler, -1, sizeof(strahler));
    cout << k << ' ' << func(n) << nl;
}

int main() {
    fastio(nullptr, false);
    int tc{};
    cin >> tc;
    for(int i = 1; i <= tc; i++) solve(i);
}