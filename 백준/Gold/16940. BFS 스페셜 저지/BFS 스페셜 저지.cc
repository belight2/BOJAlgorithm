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
vector<int> adj[100'005];
int a[100'005];

int mx; // max depth
int depth[100'005], chk[100'005], start_idx[100'005];

bool is_correct_path(int cur) {
    if(depth[cur] == mx) {
        return 1;
    }

    int& st = start_idx[depth[cur] + 1];
    int en = st + sz(adj[cur]) - (cur != 1);

    bool ans = 1;
    for(int i = st; i < en; i++) {
        if(!binary_search(all(adj[cur]), a[i])) {
            st = en;
            return 0;
        }
        ans &= is_correct_path(a[i]);
    }
    st = en;

    return ans;
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
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        sort(all(adj[i]));
    }

    qi q;
    q.push(a[0]);
    depth[a[0]] = 1;
    while(sz(q)) {
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]) {
            if(depth[nxt]) continue;
            depth[nxt] = depth[cur] + 1;
            q.push(nxt);
        }
    }

    for(int i = 0; i < n; i++) {
        chk[i] = depth[a[i]];
        mx = max(mx, chk[i]);
    }

    if(!is_sorted(chk, chk + n) || a[0] != 1) {
        cout << 0;
        return 0;
    }

    for(int i = 1; i <= mx; i++) {
        start_idx[i] = lower_bound(chk, chk + n, i) - chk;
    }

    cout << is_correct_path(a[0]);
}